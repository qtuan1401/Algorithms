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
        int n;
        cin >> n;
        vector < int > a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());

        vector < int > marked(n, 0);
        for (int i = 0; i < n; i++) {
            if (a[i] % a[0] == 0) marked[i] = 1;
        }

        int pos = 0;
        for ( ; pos < n; pos++) {
            if (marked[pos] == 0) break;
        }

        bool found = true;
        for (int i = 0; i < n; i++) {
            if (marked[i] == 0 && a[i] % a[pos] != 0) {
                found = false;
                break;
            }
        }
        if (found) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}