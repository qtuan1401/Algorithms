#include <bits/stdc++.h>

using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    while (tests--) {
        int n;
        string s;
        cin >> n;
        cin >> s;
        for (int i = 0; i < n; i++) {
            cout << s[i] << s[i];
        }
    }
    return 0;
}