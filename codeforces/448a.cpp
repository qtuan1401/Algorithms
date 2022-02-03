#include <bits/stdc++.h>

using namespace std;

int main() {
    int a1, a2, a3, b1, b2, b3, n;
    cin >> a1 >> a2 >> a3;
    cin >> b1 >> b2 >> b3;
    cin >> n;
    a1 += a2 + a3;
    b1 += b2 + b3;
    //cout << a1 << " " << b2 << endl;
    if (a1 / 5 + (a1 % 5 != 0) + b1 / 10 + (b1 % 10 != 0) <= n)
        cout << "YES";
    else
        cout << "NO";
}