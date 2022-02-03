#include <bits/stdc++.h>
 
using namespace std;

int main() {
    int r, h;
    cin >> r >> h;
    double m = 1.0 * (h % r) / r;
    cout << h / r * 2 + 1 + (m > 0.495) + (m > 0.866);
    return 0;
}
