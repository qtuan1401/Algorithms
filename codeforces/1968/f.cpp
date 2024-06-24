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

vector < int > sum, val;

int getId(int x) {
    if (x < 0) return 0;
    return lower_bound(val.begin(), val.end(), x) - val.begin();
}

int calcXor(int l, int r) {
    if (l == 0) return sum[r];
    return sum[r] ^ sum[l - 1];
}

int bs(vector < int > & a, int val) {
    int pos = -1;
    int l = 0, r = (int)a.size() - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (a[mid] <= val) {
            pos = a[mid];
            l = mid + 1; 
        } else r = mid - 1;
    }
    return pos;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests;
    cin >> tests;
    while (tests--) {
        int n, q;
        cin >> n >> q;
        vector < int > a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        val.clear();
        resetVec < int > (sum, n, 0);
        sum[0] = a[0];
        val.push_back(0);
        val.push_back(a[0]);
        for (int i = 1; i < n; i++) {
            sum[i] = sum[i - 1] ^ a[i]; 
            val.push_back(sum[i]);
        }
        // for (int i = 0; i < n; i++) cout << sum[i] << " ";
        // cout << endl;

        vector < int > l(q), r(q);
        for (int i = 0; i < q; i++) {
            cin >> l[i] >> r[i];
            l[i]--; r[i]--;
            if (l[i] > 0) val.push_back(sum[l[i] - 1]);
            val.push_back(sum[r[i]]);
        }
        sort(val.begin(), val.end());
        val.erase(unique(val.begin(), val.end()), val.end());
        vector < vector < int > > pos(val.size());

        for (int i = 0; i < n; i++) {
            pos[getId(sum[i])].push_back(i);
        }

        for (int i = 0; i < q; i++) {
            int x = calcXor(l[i], r[i]);
            // cout <<x << endl;
            if (x == 0) {
                int id = getId(sum[r[i]]);
                int pp = lower_bound(pos[id].begin(), pos[id].end(), l[i]) - pos[id].begin();
                if (pp < pos[id].size()) pp = pos[id][pp];
                else pp = n + 1;
                // cout << pp << 
                if (pp <= r[i] && pp >= l[i]) {
                    cout << "YES\n";
                } else {
                    cout << "NO\n";
                }
            } else {
                int id = 0;
                if (l[i] > 0) id = getId(sum[l[i] - 1]);
                // for (auto & e : pos[id]) cout << e << " ";
                // cout << endl;
                
                int rr = bs(pos[id], r[i] - 1);
                // cout << id << " " << rr << endl;
                if (rr == -1) {
                    cout << "NO\n";
                    continue;
                }
                id = getId(sum[r[i]]);
                int ll = lower_bound(pos[id].begin(), pos[id].end(), l[i]) - pos[id].begin();
                
                if (ll < pos[id].size()) ll = pos[id][ll];
                else ll = n + 1;
                
                if (ll >= l[i] && ll <= rr) {
                    cout << "YES\n";
                } else {
                    cout << "NO\n";
                }
            }
        }
    }
    return 0;
}