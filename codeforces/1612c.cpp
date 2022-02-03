#include <bits/stdc++.h>

using namespace std;

bool check(int n, int k, long long x) {
    // cout << n << " " << k << " " << x << endl;
    long long sum = 0;
    if (n > k) {
        n -= k;
        sum = 1ll * k * (k + 1) / 2;
        sum += 1ll * k * (k - 1) / 2;
        k = k - 1 - n;
        sum -= 1ll * k * (k + 1) / 2;
    } else {
        sum += 1ll * n * (n + 1) / 2;
    }
    // cout << sum << endl;
    return sum < x;
}

int bs(int l, int r, long long x) {
    int ans = 0;
    int k = (r + 1) / 2;
    while (l <= r) {
        int mid = (1ll * l + r) >> 1;
        // cout << mid << " " << l << " " << r << endl;
        if (check(mid, k, x)) {
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int k;
        long long x;
        cin >> k >> x;
        cout << min(bs(1, 2 * k - 1, x) + 1, 2 * k - 1) << '\n';
    }
    return 0;
}