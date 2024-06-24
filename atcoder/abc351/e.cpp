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

vector < int > seg, lazy;

void update(int id, int l, int r, int u, int v, int val) {
    if(lazy[id] != 0) {
        seg[id] += lazy[id];
        if (l != r) {
            lazy[id * 2 + 1] += lazy[id];             
            lazy[id * 2 + 2] += lazy[id];              
        }
        lazy[id] = 0;                                  
    }
    if (l > r || l > v || r < u)
        return ;
    if(u <= l && r <= v) {
        seg[id] += val;
        if(l != r) {
            lazy[id * 2 + 1] += val;
            lazy[id * 2 + 2] += val;
        }
        return ;
    }
    int mid = (l + r) / 2;
    update(id * 2 + 1, l, mid, u, v, val);      
    update(id * 2 + 2, mid + 1, r, u, v, val);  
    seg[id] = max(seg[id * 2 + 1], seg[id * 2 + 2]);
}

int query(int id, int l, int r, int u, int v) {
    if (l > r || l > v || r < u)
        return 0;
    if (lazy[id] != 0) {
        seg[id] += lazy[id];
        if (l != r) {
            lazy[id * 2 + 1] += lazy[id];             
            lazy[id * 2 + 2] += lazy[id];              
        }
        lazy[id] = 0;                                  
    }
    if (u <= l && r <= v)
        return seg[id];
    int mid = (l + r) / 2;
    int p1 = query(id * 2 + 1, l, mid, u, v);
    int p2 = query(id * 2 + 2, mid + 1, r, u, v);
    return max(p1, p2);
}

long long calc(vector < pii > & a) {
    sort(a.begin(), a.end(), [&](pii & lhs, pii & rhs) {
        return lhs.first + lhs.second < rhs.first + rhs.second;
    });

    int l = 0;
    for (int i = 0; i < p.size(); i++) {
        while (p[i].first + p[i].second == p[l].first + p[l].second) {
            
        }
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    while (tests--) {
        int n;
        cin >> n;
        vector < pii > odd, even;
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            x--; y--;
            if ((x + y) % 2 == 0) {
                even.push_back(pii(x, y));
            } else {
                odd.push_back(pii(x, y));
            }
        }

        cout << calc(odd) + calc(even);
    }
    return 0;
}