// codeforces 960f
#include <bits/stdc++.h>
 
using namespace std;
 
#define left this_is_left
#define right this_is_right
 
const int MAXN = 1e5 + 10;
 
struct segmentTree {
    int l, r, val;
    segmentTree *left, *right;
    segmentTree() {}
    segmentTree(const int _l, const int _r) {
        l = _l;
        r = _r;
        left = right = NULL;
        val = 0;
    }
 
    void update(int id, int nVal) {
        if (l > id || id > r)
            return ;
        if (l == id && id == r) {
            val = nVal;
            return ;
        }
        int mid = (l + r) >> 1;
        if (id <= mid) {
            if (!left)
                left = new segmentTree(l, mid);
            left -> update(id, nVal);
        } else {
            if (!right)
                right = new segmentTree(mid + 1, r);
            right -> update(id, nVal);
        }
        val = 0;
        if (left)
            val = max(val, left -> val);
        if (right)
            val = max(val, right -> val);
    }
 
    int get(int u, int v) {
        if (u > r || l > v)
            return 0;
        if (u <= l && r <= v)
            return val;
        int ans = 0;
        if (left)
            ans = max(ans, left -> get(u, v));
        if (right)
            ans = max(ans, right -> get(u, v));
        return ans;
    }
};
 
int n, m;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    vector < segmentTree > root;
    for(int i = 0; i < n; i++)
        root.push_back(segmentTree(0, MAXN));
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        //cout << u << " " << v << " " << w << endl;
        int ans = root[u].get(0, w - 1);
        root[v].update(w, ans + 1);
    }
 
    int ans = 0;
    for(int i = 0; i < n; i++)
        ans = max(ans, root[i].get(0, MAXN));
    cout << ans;
    return 0;
}