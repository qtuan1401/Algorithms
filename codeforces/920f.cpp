#include <bits/stdc++.h>

using namespace std;

t1def pair < int, int > II;

const int MXN = 1e6 + 10;
const int INF = 1e9;

int divisor[MXN], cnt1[MXN], a[MXN];
long long fw[MXN][2];
set < int > s[15];
int n, m;

void eratos(int n) {
    for(int i = 1; i <= n; i++)
        for(int j = i; j <= n; j += i)
            divisor[j]++;
}

void update(int x, int val, int t1) {
    while (x < MXN) {
        fw[x][t1] += val;
        x += (x & (-x));
    }
}

long long get(int x, int t1) {
    long long res = 0;
    while (x > 0) {
        res += fw[x][t1];
        x -= (x & (-x));
    }
    return res;
}

int main() {
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    eratos(1000000);
    //for(int i = 1; i <= 10; i++)
    //    cout << divisor[i] << " ";
    //cout << divisor[966000] << endl;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        //cnt1[i] = (a[i] == 1);
        if (a[i] > 2) {
            s[0].insert(i);
            update(i, a[i], 1);
        } else {
            update(i, a[i], 0);
        }
    }

    //for(int i = 1; i <= n; i++)
    //    cout << get(1, 1, n, i, i, 1) << " ";
    //for(int i = 0; i < n; i++)
    //    cout << cnt1[i] << " ";
    while (m--) { 
        int t1, l, r;
        cin >> t1 >> l >> r;
        if (t1 == 1) {
            for(int i = 6; i >= 0; i--) {
                if (s[i].empty())
                    continue; 
                for(set < int > :: iterator it = s[i].lower_bound(l); it != s[i].end() && (*it) <= r; it = s[i].erase(it)) {
                    int pos = *it;
                    int val = divisor[a[pos]];
                    update(pos, -a[pos], 1);
                    if (val > 2) {
                        s[i + 1].insert(pos);
                        update(pos, val, 1);
                    } else {
                        update(pos, 2, 0);
                    }
                    a[pos] = val;
                    //s[i].erase(it);
                    //it = s[i].lower_bound(l);
                } 
            }
        } else {
            cout << get(r, 1) - get(l - 1, 1) + (get(r, 0) - get(l - 1, 0)) << '\n';
        }
    } 
    return 0;
}
