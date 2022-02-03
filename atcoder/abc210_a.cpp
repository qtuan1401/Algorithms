#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, a, x, y;
    cin >> n >> a >> x >> y;
    cout << min(n, a) * x + max(0, n - a) * y << '\n';
    return 0;
}