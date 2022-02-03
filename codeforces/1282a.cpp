#include <bits/stdc++.h>

using namespace std;

int a, b, c, r, T;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> T;
    while (T--) {
        cin >> a >> b >> c >> r;
        if (a > b)
            swap(a, b);
        cout << b - a + min(0, max(a, c - r) - min(b, c + r)) << '\n';
    }
} 