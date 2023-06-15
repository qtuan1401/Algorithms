#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    while (tests--) {
        int x;
        cin >> x;
        if (x == 0) {
            cout << 0 << '\n';
            continue;
        }
        vector < int > digits;
        while (x > 0) {
            digits.push_back(x % 10);
            x /= 10;
        }

        int n = digits.size();

        for (int i = 0; i < n - 3; i++) {
            digits[i] = 0;
        }

        for (int i = n - 1; i >= 0; i--) cout << digits[i];
        cout << '\n';
    }
    return 0;
}