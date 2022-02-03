#include<bits/stdc++.h>

#define y1 this_is_y1

using namespace std;

int a[6];

int main() {
    int x, y, z, x1, y1, z1;
    cin >> x >> y >> z >> x1 >> y1 >> z1 >> a[0] >> a[1] >> a[2] >> a[3] >> a[4] >> a[5];
    cout << a[0] * (y < 0) + a[1] * (y > y1) + a[2] * (z < 0) + a[3] * (z > z1) + a[4] * (x < 0) + a[5] * (x > x1);
    return 0;
}