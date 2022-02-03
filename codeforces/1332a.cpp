#include <bits/stdc++.h>

#define y1 qwery1

using namespace std;

int main() {
    // freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int x, y, x1, y1, x2, y2;
        cin >> x >> y >> x1 >> y1 >> x2 >> y2;
        if (x1 == x && x2 == x && (a > 0 || b > 0)) {
            cout << "No\n";
            continue;
        }

        if (y1 == y && y2 == y && (c > 0 || d > 0)) {
            cout << "No\n";
            continue;
        }
        
        a = -a; c = -c;
        a += b;
        c += d;
        
        if (x + a >= x1 && x + a <= x2 && y + c >= y1 && y + c <= y2)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}