#include <bits/stdc++.h>

using namespace std;

long long a, b, n;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> a >> b;
    if ((b - a) % 2 == 0)
        cout << (b - a) / 2;
    else cout << (b - a - 1) / 2 + 1 + min(a - 1, n - b);
    return 0;
}