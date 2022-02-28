#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int u, v;
        cin >> u >> v;
        cout << -1ll * u * u << " " << 1ll * v  * v << '\n';
    }
    return 0;
}