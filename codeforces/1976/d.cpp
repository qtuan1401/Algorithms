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

vector < int > seg;

void update(int id, int l, int r, int pos, int val) {
    if (pos < l || pos > r)
        return ;
    
    if (l == r && r == pos) {
        seg[id] = val;
        return ;
    }
    int mid = (l + r) >> 1;
    update(id * 2, l, mid, pos, val);
    update(id * 2 + 1, mid + 1, r, pos, val);
    seg[id] = max(seg[id * 2], seg[id * 2 + 1]);
}

int get(int id, int l, int r, int u, int v) {
    if (v < l || r < u)
        return 0;
    if (u <= l && r <= v)
        return seg[id];
    int mid = (l + r) >> 1;
    return max(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}

vector < int > fw;

void up(int x, int n, int val) {
    while (x <= n) {
        fw[x] += val;
        x += (x & (-x));
    }
}

int query(int x) {
    int res = 0;
    while (x > 0) {
        res += fw[x];
        x -= (x & (-x));
    }
    return res;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests;
    cin >> tests;
    while (tests--) {
        string s;
        cin >> s;
        int n = s.size();

        vector < int > sum(n, 0);
        vector < vector < int > > pos(n + 1);
        pos[0].push_back(0);
        resetVec(seg, (n + 1) * 4, 0);
        resetVec(fw, 2 * n + 5, 0);
        sum[0] += (s[0] == '(' ? 1 : -1);
        pos[sum[0]].push_back(1);
        for (int i = 1; i < n; i++) {
            int val = (s[i] == '(' ? 1 : -1);
            sum[i] = sum[i - 1] + val;
            pos[sum[i]].push_back(i + 1);
        }

        for (int i = 1; i <= n; i++) update(1, 1, n, i, sum[i - 1]);
        long long ans = 0;
        for (int val = 0; val <= n; val++) {
            // cout << val << endl;
            vector < pii > pp;
            int m = pos[val].size();
            vector < int > mx(m), cnt(m);
            for (int j = m - 2; j >= 0; j--) {
                int p2 = pos[val][j + 1];
                int p1 = pos[val][j];

                mx[j] = get(1, 1, n, p1 + 1, p2);
                cnt[j] = 1;
            }
            stack < int > stk;
            for (int i = m - 2; i >= 0; i--) {
                while (stk.size() && mx[stk.top()] <= mx[i]) {
                    cnt[i] += cnt[stk.top()];
                    up(mx[stk.top()] + 1, 2 * n + 1, -cnt[stk.top()]);
                    stk.pop();
                }
                up(mx[i] + 1, 2 * n + 1, cnt[i]);
                stk.push(i);

                int p1 = pos[val][i];
                ans += query((p1 == 0 ? 0 : sum[p1 - 1]) * 2 + 1);
            }

            while (stk.size()) {
                up(mx[stk.top()] + 1, 2 * n + 1, -cnt[stk.top()]);
                stk.pop();
            }
        }

        cout << ans << '\n';
    }
    return 0;
}