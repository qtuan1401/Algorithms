#include <bits/stdc++.h>

using namespace std;

double calc(int u, int v, int x, int y) {
    return (sqrt((u - x) * (u - x) + (v - y) * (v - y)));
}

int main() {
    ios_base::sync_with_stdio(0);
    int x, y;
    cin >> x >> y;
    double res = 1e15;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int u, v, s;
        cin >> u >> v >> s;
        res = min(res, calc(u, v, x, y) / s);
    }
    cout << fixed << setprecision(10);
    cout << res;
    return 0;
}