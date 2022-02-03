#include <bits/stdc++.h>

using namespace std;

int n, s, res;

int main() {
    cin >> n >> s;
    res = -1;
    while (n--) {
        int x, y;
        cin >> x >> y;
        if(s * 100 >= x * 100 + y)
            res = max(res, (100 - y) % 100);
    }
    cout << res;
}