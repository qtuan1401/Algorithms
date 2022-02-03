#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int z, y, a, b, c;
        cin >> z >> y >> a >> b >> c;
        z -= y;
        if (z < a + b + c)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;
}