#include <bits/stdc++.h>

using namespace std;

int mask(int x) {
    if (x == 0)
        return 0;
    if (x % 10 == 4 || x % 10 == 7)
        return mask(x / 10) * 10 + x % 10;
    return mask(x / 10);
}

int main() {
    ios_base::sync_with_stdio(0);
    int a, b;
    cin >> a >> b;
    while (mask(++a) != b);
    cout << a;
    return 0;
}