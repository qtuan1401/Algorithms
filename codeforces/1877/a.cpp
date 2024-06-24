#include <bits/stdc++.h>

using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests;
    cin >> tests;
    while (tests--) {
        int n;
        cin >> n;

        long long sum = 0;
        for (int i = 0; i < n - 1; i++) {
            int x;
            cin >> x;
            sum += x;
        }

        cout << -sum << endl;
    }
    return 0;
}