#include <bits/stdc++.h>

using namespace std;

int main() {
    long long r, g, b;
    cin >> r >> g >> b;
    cout << min((r + g + b) / 3, min(r + g, min(g + b, r + b )));
    return 0;
}