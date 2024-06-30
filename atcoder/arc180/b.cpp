#include <bits/stdc++.h>

using namespace std;

template < class T >
void resetVec(vector < T > & a, int sz, T val) {
    a.clear();
    a.resize(sz, val);
}

typedef long double ld;
typedef long long ll;
typedef pair < int, int > pii;

int n, k;
vector < int > p, f;
vector < pii > ans;
map < pii, int > marked;
vector < int > seg;
vector < int > mnp;

void update(int id, int l, int r, int u, int val) {
    if (u == l && l == r) {
        seg[id] = val;
        mnp[id] = l;
        return ;
    }
    int mid = (l + r) >> 1;
    if (u <= mid)
        update(id * 2, l, mid, u, val);
    else update(id * 2 + 1, mid + 1, r, u, val);
    seg[id] = max(seg[id * 2], seg[id * 2 + 1]);
    if (seg[id] == seg[id * 2]) mnp[id] = mnp[id * 2];
    else mnp[id] = mnp[id * 2 + 1];
}

pii get(int id, int l, int r, int u, int v) {
    if (l > v || r < u)
        return pii(-1, -1);
    if (u <= l && r <= v)
        return pii(mnp[id], seg[id]);
    int mid = (l + r) >> 1;
    int lv = get(id * 2, l, mid, u, v).second;
    int rv = get(id * 2 + 1, mid + 1, r, u, v).second;
    if (lv > rv) return pii(mnp[id * 2], lv);
    return pii(mnp[id * 2 + 1], rv);
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    while (tests--) {
        cin >> n >> k;
        vector < int > loc(n, 0);
        p.resize(n);
        f.resize(n);
        seg.resize(n * 4 + 5);
        mnp.resize(n * 4 + 5);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
            p[i]--;
        }
        bool isSwap = true;
        while (isSwap) {
            for (int i = 0; i < n; i++) loc[p[i]] = i;
            for (int i = 0; i <= n * 4; i++) seg[i] = mnp[i] = -1;
            for (int i = 0; i < n; i++) update(1, 1, n, i + 1, p[i]);
            isSwap = false;
            cout << "start" << endl;
            for (int i = 0; i < n; i++) {
                if (loc[i] + k + 1 > n) continue;
                pii cur = get(1, 1, n, loc[i] + k + 1, n);
                int pos = cur.first;
                cout << i << " " << cur.second << endl; 
                if (pos != -1 && i > cur.second) {
                    ans.push_back(pii(loc[i] + 1, pos + 1));
                    swap(p[loc[i]], p[pos]);
                    isSwap = true;
                    break;
                }
            }

            for (int i = 0; i < n; i++) cout << p[i] << " ";
            cout << endl;
        }
        
        cout << ans.size() << '\n';
        for (int i = 0; i < ans.size(); i++) cout << ans[i].first << " " << ans[i].second << '\n';
    }
    return 0;
}

/*
3 1 2
1 3 2
1 2 3
*/