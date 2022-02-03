#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int a, b, c;
    cin >> a >> b >> c;
    if (a == b || (c && (b - a) % c == 0 && (b - a) / c >= 1))
        cout << "YES";
    else
        cout << "NO";
    return 0;
}