#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int x, y;
    cin >> x >> y;
    x--; y--;
    swap(s[x], s[y]);
    cout << s;
    return 0;
}