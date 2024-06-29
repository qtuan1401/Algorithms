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

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests;
    cin >> tests;
    while (tests--) {
        int n, m;
        cin >> n >> m;
        vector < vector < int > > a(n, vector < int > (m, 0));
        vector < vector < int > > b(n, vector < int > (m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) cin >> a[i][j];
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) cin >> b[i][j];
        }
    
        vector < int > order;
        map < int, int > marked;
        for (int i = 0; i < m; i++) marked[a[0][i]] = 1;
        bool found = false;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < m; j++) {
                cnt += marked[b[i][j]];
            }

            if (cnt == m) {
                map < int, int > mp;
                found = true;
                for (int j = 0; j < m; j++) {
                    mp[a[0][j]] = j;
                }
                for (int j = 0; j < m; j++) {
                    order.push_back(mp[b[i][j]]);
                }
                break;
            }
        }

        if (!found) {
            cout << "NO\n";
            continue;
        }

        for (int i = 0; i < n; i++) {
            vector < int > temp(m, 0);
            for (int j = 0; j < m; j++) temp[j] = a[i][order[j]];
            for (int j = 0; j < m; j++) a[i][j] = temp[j];
        }

        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < m; j++) cout << a[i][j] << " ";
        //     cout << endl;
        // }

        map < int, int > pos;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) pos[b[i][j]] = i;
        }

        for (int i = 0; i < n; i++) {
            int row = pos[a[i][0]];
            // cout << i << " " << row << endl;
            for (int j = 0; j < m; j++) {
                if (a[i][j] != b[row][j]) {
                    found = false;
                }
            }
        }

        if (found) cout << "YES\n";
        else cout << "NO\n";
    } 
    return 0;
}