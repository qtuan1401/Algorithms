#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("../test.in", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, x;
    cin >> n >> x;
    vector < int > a(n - 1);

    int sum = 0;
    for (int i = 0; i < n - 1; i++) {
        cin >> a[i];
        sum += a[i];
    }

    int mn = *min_element(a.begin(), a.end());
    int mx = *max_element(a.begin(), a.end());

    for (int i = 0; i <= 100; i++) {
        int cur = sum;
        if (i > mx) {
            cur = sum - mn;
        } else if (i < mn) {
            cur = sum - mx;
        } else {
            cur = sum - mx - mn + i;
        }

        if (cur >= x) {
            cout << i << '\n';
            return 0;
        }
    }

    cout << "-1\n";
    return 0;
}