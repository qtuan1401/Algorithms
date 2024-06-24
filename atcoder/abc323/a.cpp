#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("../test.in", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);

    string s;
    cin >> s;
    bool ok = true;
    for (int i = 1; i < s.size(); i += 2) {
        if (s[i] == '1') {
            ok = false;
            break;
        }
    }

    cout << (ok ? "Yes" : "No") << '\n';
    return 0;
}