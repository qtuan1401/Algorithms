#include <bits/stdc++.h>

using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    while (tests--) {
        bool ok = true;
        long long n;
        cin >> n;
        while (n % 2 == 0) n /= 2;
        while (n % 3 == 0) n /= 3;
        if (n == 1) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}