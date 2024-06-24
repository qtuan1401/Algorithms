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
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i]--;
        }

        bool p = false;
        for (int i = 0; i < n; i++) {
            // cout << a[i] << " " << endl;
            if (i == a[a[i]]) {
                p = true;
                break;
            }
        }

        if (p) cout << "2";
        else cout << "3";
        cout << '\n';
    }
    return 0;
}