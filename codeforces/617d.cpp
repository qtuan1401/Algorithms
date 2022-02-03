#include <bits/stdc++.h>
 
using namespace std;
 
int x[3], y[3];
 
inline bool isBetween(int a, int b, int c) {
    return min(a, b) <= c && c <= max(a, b);
}
 
inline bool check(int i, int j, int k) {
    return ((x[k] == x[i] || x[k] == x[j]) && isBetween(y[i], y[j], y[k])) ||
           ((y[k] == y[i] || y[k] == y[j]) && isBetween(x[i], x[j], x[k]));
}
 
int main() {
    for (int i = 0; i < 3; i++)
        cin >> x[i] >> y[i];
 
    if ((x[0] == x[1] && x[1] == x[2]) || (y[0] == y[1] && y[1] == y[2]))
        cout << "1";
    else if (check(0, 1, 2) || check(0, 2, 1) || check(1, 2, 0))
        cout << "2";
    else
        cout << "3\n";
    return 0;
}