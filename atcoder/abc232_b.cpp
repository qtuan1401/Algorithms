#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s, t;
    cin >> s >> t;
    int n = s.size();
    bool ok = true;
    int diff = t[0] - s[0];
    if (diff < 0) diff += 26;
    for (int i = 1; i < n; i++) {
        int k = t[i] - s[i];
        if (k < 0) k += 26;
        if (k != diff) {
            ok = false;
            break;
        }
    }
    if (ok) cout << "Yes";
    else cout << "No";
}