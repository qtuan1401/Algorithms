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
        bool found = false;
        for (int i = 0; i < n; i++) {
            bool ok1 = true, ok2 = true;
            for (int j = 1; j < i; j++) {
                if (a[j - 1] > a[j]) ok1 = false;
            }

            for (int j = i + 1; j < n; j++) {
                if (a[j - 1] > a[j]) ok2 = false;
            }

            if (i == 0 && ok2) found = true;
            else if (i > 0) {
                if (ok1 && ok2 && a[0] >= a[n - 1]) {

                    found = true;
                }
            }
        }
        if (found) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}