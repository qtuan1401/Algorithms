#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;

bool isGood(string & s) {
    int n = s.size();
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) return false;
    }

    return true;
}

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
        string s, t;
        cin >> s >> t;

        if (isGood(s)) cout << "YES\n";
        else {
            if (isGood(t)) {
                bool ok = true;
                for (int i = 1; i < n; i++) {
                    if (s[i] == s[i - 1]) {
                        if (s[i - 1] == t[0] || s[i] == t[m - 1]) {
                            ok = false;
                            break;
                        }
                    }
                }

                if (ok) cout << "YES\n";
                else cout << "NO\n";
            } else {
                cout << "NO\n";
            }
        }
    }
    return 0;
}