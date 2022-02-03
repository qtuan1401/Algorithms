#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        long long a, b, n, m;
        cin >> a >> b >> n >> m;
        cout << ((m <= min(a, b) && n + m <= a + b) ? "Yes" : "No") << '\n';
    }
    return 0;
}