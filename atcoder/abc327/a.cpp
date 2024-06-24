#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    while (tests--) {
        string s;
        int n;
        cin >> n >> s;

        bool ok = false;
        for (int i = 1; i < n; i++) {
            if (s[i] == 'a' && s[i - 1] == 'b') {
                ok = true;
                break;
            }

            if (s[i] == 'b' && s[i - 1] == 'a') {
                ok = true;
                break;
            }
        }
        if (ok) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}