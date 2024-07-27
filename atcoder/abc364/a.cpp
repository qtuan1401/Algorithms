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
    int tests = 1;
    while (tests--) {
        int n;
        cin >> n;
        vector < string > s(n);
        for (int i = 0; i < n; i++) cin >> s[i];
        bool ok = true;
        for (int i = 1; i < n - 1; i++) {
            if (s[i] == "sweet" && s[i - 1] == "sweet") {
                ok = false;
                break;
            }
        }

        if (ok) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}