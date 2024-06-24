// codeforces 985e
#include <bits/stdc++.h>

using namespace std;

typedef pair < int, int > II;

const int MAXN = 5e5 + 10;
const int INF = 1e9;

int a[MAXN], seg[MAXN * 4];
int n, k, d;

int bsL(int l, int r, int val) {
    int pos = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (a[mid] - val <= d) {
            pos = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    return pos;
}

void update(int id, int l, int r, int u, int val) {
    if (u == l && l == r) {
        seg[id] = val;
        return ;
    }
    int mid = (l + r) >> 1;
    if (u <= mid)
        update(id * 2, l, mid, u, val);
    else update(id * 2 + 1, mid + 1, r, u, val);
    seg[id] = min(seg[id * 2], seg[id * 2 + 1]);
}

int get(int id, int l, int r, int u, int v) {
    if (l > v || r < u)
        return INF;
    if (u <= l && r <= v)
        return seg[id];
    int mid = (l + r) >> 1;
    return min(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}

int main() {
    //freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n >> k >> d;
    for(int i = 0; i < n; i++) 
        cin >> a[i];
    sort(a, a + n);
    //for(int i = 0; i < n; i++)
    //    cout << a[i] << " ";
    //cout << endl;
    int prePos = -1;
    vector < II > segs;
    for(int i = 0; i < n; i++) {
        int pos = bsL(i, n - 1, a[i]);
        if (pos > prePos && pos - i + 1 >= k) {
            //cout << a[i] << " " << a[pos] << endl;
            segs.push_back(II(i + 1, pos + 1));
            prePos = pos;
        }
    }
    sort(segs.begin(), segs.end());
    for(int i = 1; i <= n; i++)
        update(1, 1, n, i, INF);
    //update(1, 1, n, 5, 5);
    //cout << get(1, 1, n, 5, 5) << endl;
    for(int i = 0; i < segs.size(); i++) {
        int l = segs[i].first, r = segs[i].second;
        if (l == 1) {
            update(1, 1, n, r, l + k - 1);
            continue;
        }
        int mnL = get(1, 1, n, l - 1, r);
        //cout << mnL << endl;
        l = max(l, mnL + 1);
        if (l == INF) {
            cout << "NO";
            return 0;
        }
        //cout << l << " " << r << endl;
        if (r - l + 1 >= k)
            update(1, 1, n, r, l + k - 1);
    }
    if (get(1, 1, n, n, n) != INF)
        cout << "YES";
    else cout << "NO";
    return 0;
}
