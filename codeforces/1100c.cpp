#include <bits/stdc++.h>

using namespace std;

const double PI = 3.14159265359;

int main() {
    ios_base::sync_with_stdio(0);
    double n, r;
    cin >> n >> r;
    double angle = (360.0 / n) / 2;
    //cout << angle << endl;
    double temp = sin(angle * PI / 180);
    //cout << temp << endl;
    cout << fixed << setprecision(15);
    cout << temp * r / (1.0 - temp);
    return 0;
}