#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    while (tests--) {
        int n;
        cin >> n;
        int l = n - n % 5;
        int r = l + 5;
        if (abs(l - n) < abs(r - n)) cout << l;
        else cout << r;
    }
    return 0;
}