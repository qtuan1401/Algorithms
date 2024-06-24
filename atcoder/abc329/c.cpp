#include <bits/stdc++.h>

using namespace std;

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
        string s;
        cin >> s;
        long long ans = 0;
        for (int j = 0; j < 26; j++) {
            int cur = 0, mx = 0;
            for (int i = 0; i < n; i++) {
                int c = s[i] - 'a';
                if (c == j) {
                    cur++;
                    if (cur > mx) {
                        mx = cur;
                        ans++;
                    }
                } else cur = 0;
            }
        }

        cout << ans << '\n';
    }
    return 0;
}