#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        long long x, y;
        cin >> n >> x >> y;
        long long sum = x;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            sum += x;
        }
        if (sum % 2 == y % 2) cout << "Alice\n";
        else cout << "Bob\n";
    }
    return 0;
}