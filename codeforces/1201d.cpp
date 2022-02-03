#include <bits/stdc++.h>

using namespace std;

const long long MAXN = 2e5 + 10;
const long long INF = 1e15;

typedef pair < int, int > II;

int cL[MAXN], cR[MAXN], l[MAXN], r[MAXN], b[MAXN];
long long f[5][5];
int n, m, k, q, id;

long long calcL(II p, int np, int lim, int row, int id, int type) {
    int l = cL[np], r = cR[np];
    if (l == 0)
        l = r;
    if (r == 0)
        r = l;
    long long res = INF;
    if (l < lim) 
        res = min(res, f[id ^ 1][type] + row - p.first + abs(p.second - l) + abs(l - np));
    if (r < lim)
        res = min(res, f[id ^ 1][type] + row - p.first + abs(p.second - r) + abs(r - np));
    return res;
}

long long calcR(II p, int np, int lim, int row, int id, int type) {
    int l = cL[np], r = cR[np];
    long long res = INF;
    if (l == 0)
        l = r;
    if (r == 0)
        r = l;
    if (l > lim) 
        res = min(res, f[id ^ 1][type] + row - p.first + abs(p.second - l) + abs(l - np));
    if (r > lim)
        res = min(res, f[id ^ 1][type] + row - p.first + abs(p.second - r) + abs(r - np));   
    return res;
}

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> k >> q;
    for(int i = 1; i <= n; i++)
        l[i] = 1e9;
    for(int i = 0; i < k; i++) {
        int row, col;
        cin >> row >> col;
        //cout << row << " " << col << endl;
        //if (row == 1 && col == 1)
        //    continue;
        l[row] = min(l[row], col);
        r[row] = max(r[row], col);
    }
    //for(int i = 1; i <= n; i++)
    //    cout << l[i] << " " << r[i] << endl;
    //cout << l[1] << " " << r[1] << endl;
    for(int i = 0; i < q; i++) {
        int x;
        cin >> x;
        b[x] = x;
    }
    for(int i = 1; i <= m; i++)
        if (b[i] == 0)
            cL[i] = cL[i - 1];
        else cL[i] = b[i];
    for(int i = m; i >= 1; i--)
        if (b[i] == 0)
            cR[i] = cR[i + 1];
        else cR[i] = b[i];
    int id = 0;
    II pL = II(1, 1), pR = II(1, 1);
    //cout << l[1] << " " << r[1] << endl;
    for(int i = 1; i <= n; i++) {
        if (l[i] == 1e9)
            continue;
        //cout << id << endl;
        if (i == 1) {
            f[id][0] = l[i] - 1 + (r[i] - l[i]) * 2;
            f[id][1] = r[i] - 1;
         //   return 0;
        } else {
            long long tL1 = calcL(pL, l[i], r[i] + (l[i] == r[i]) * 1e9, i, id, 0);
            long long tL2 = calcL(pR, l[i], r[i] + (l[i] == r[i]) * 1e9, i, id, 1);
            long long tR1 = calcR(pL, r[i], l[i] * (l[i] != r[i]), i, id, 0);
            long long tR2 = calcR(pR, r[i], l[i] * (l[i] != r[i]), i, id, 1);
        //    cout << tL1 << " " << tL2 << " " << tR1 << " " << tR2 << endl;
            long long tL = min(tL1, tL2), tR = min(tR1, tR2);
            //if (tL < INF)
            f[id][1] = min(tL + r[i] - l[i], tR + (r[i] - l[i]) * 2);
            f[id][0] = min(tR + r[i] - l[i], tL + (r[i] - l[i]) * 2);
        }
        //cout << i << " " << f[id][0] << " " << f[id][1] << endl;
        pL = II(i, l[i]); pR = II(i, r[i]);
        id ^= 1;   
    }
    //cout << "0";
    cout << min(f[id ^ 1][0], f[id ^ 1][1]);
    return 0;
}