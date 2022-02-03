#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        int x, y;
        cin >> x >> y;
        if ((x + y) % 2 != 0) {
            cout << "-1 -1\n";
            continue;
        }

        if ((x + y) / 2 - y >= 0)
            cout << (x + y) / 2 - y << " " << y << '\n';
        else
            cout << x << " " << (x + y) / 2 - x << '\n';
    }
    return 0;
}