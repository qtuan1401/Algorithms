#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int x, y, res = 0;
    cin >> x >> y;
    while (x < y) {
        x += 10;
        res++;
    }
    cout << res;
    return 0;
}