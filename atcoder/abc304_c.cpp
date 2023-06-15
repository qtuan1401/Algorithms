#include <bits/stdc++.h>

using namespace std;

const int BASE = 1e3;

int dist(int u, int v, int x, int y) {
    return (u - x) * (u - x) + (v - y) * (v - y);
}

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    while (tests--) {
        int n, d;
        cin >> n >> d;
        vector < int > x(n), y(n);
        for (int i = 0; i < n; i++) {
            cin >> x[i] >> y[i];
        }

        queue < int > qu;
        vector < int > vst(n, 0);
        vst[0] = 1;
        qu.push(0);

        while (qu.size()) {
            int p = qu.front(); qu.pop();
            int u = x[p], v = y[p];
            for (int i = 0; i < n; i++) {
                if (vst[i]) continue;
                if (dist(u, v, x[i], y[i]) > d * d) continue;
                vst[i] = true;
                qu.push(i);
            }
        }

        for (int i = 0; i < n; i++) {
            if (vst[i]) cout << "Yes\n";
            else cout << "No\n";
        }
    }
    return 0;
}