#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("../test.in", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);

    int x;
    cin >> x;
    bool ok = true;
    int pre = -1;
    while (x > 0) {
        int cur = x % 10;
        if (cur <= pre) {
            ok = false;
            break;
        }
        pre = x % 10;
        x /= 10;
    }

    cout << (ok == true ? "Yes\n" : "No\n");
    return 0;
}