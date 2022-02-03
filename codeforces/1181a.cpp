#include <bits/stdc++.h>

using namespace std;

long long x, y, z;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> x >> y >> z;
    if (x % z + y % z < z)
        cout << x / z + y / z <<" " << 0;
    else cout << x / z + y / z + 1 << " " << z - max(x % z, y % z);
    return 0;
}