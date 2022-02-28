#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        vector < int > x(3), y(3);
        int mx = 0;
        for (int i = 0; i < 3; i++) {
            cin >> x[i] >> y[i];
            mx = max(mx, y[i]);
        }
        
        double res = 0;
        for (int i = 0; i < 3; i++)
            for (int j = i + 1; j < 3; j++)
                if (y[i] == y[j] && y[i] == mx)
                    res += abs(x[i] - x[j]);
                
        
        cout << fixed << setprecision(10) << res << '\n';
    }
    return 0;
}