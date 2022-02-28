#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        int a, b, c;
        cin >> a >> b >> c;
        c %= 2;
        if (c > 0) a--, b--;
        cout << a % 2 << '\n';
    }
    return 0;
}