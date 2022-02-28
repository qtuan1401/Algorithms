#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        long long n;
        cin >> n;
        cout << -n + 1 << " " << n << '\n';
    }
    return 0;
}