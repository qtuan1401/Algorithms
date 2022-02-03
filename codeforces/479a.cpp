#include <bits/stdc++.h>

using namespace std;

int a[5];

int main() {
    cin >> a[0] >> a[1] >> a[2];
    if (a[0] == 1 && a[1] == 1 && a[2] == 1)
        cout << 3;
    else if (a[0] == 1 && a[2] == 1)
        cout << a[1] + 2;
    else if (a[1] == 1)
        cout << (min(a[0], a[2]) + 1) * max(a[0], a[2]);
    else if (a[2] == 1)
        cout << a[0] * (a[1] + a[2]);
    else if (a[0] == 1)
        cout << (a[0] + a[1]) * a[2];
    else
        cout << a[0] * a[1] * a[2];
    return 0;
}