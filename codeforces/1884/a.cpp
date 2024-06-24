#include <bits/stdc++.h>

using namespace std;

bool check(int x, int k) {
    int sum = 0;
    while (x > 0) {
        sum += x % 10;
        x /= 10;
    }

    return sum % k == 0;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests;
    cin >> tests;
    while (tests--) {
        int x, k;
        cin >> x >> k;
        for (int i = x; i <= x + 1000; i++) {
            if (check(i, k)) {
                cout << i << '\n';
                break;
            }
        }
    }
    return 0;
}