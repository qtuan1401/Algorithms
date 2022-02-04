#include <bits/stdc++.h>

using namespace std;

int n;
vector < int > h;

bool check(int x) {
    vector < int > a(n);
    a = h;
    for (int i = n - 1; i >= 2; i--) {
        // int need2 = x - a[i - 1];
        int diff = min(h[i], max(0, a[i] - x));
        a[i - 2] += diff / 3 * 2;
        a[i - 1] += diff / 3;
        a[i] -= diff;
    }
    for (int i = 0; i < n; i++)
        if (a[i] < x) return false;
    return true;
}

int bs(int l, int r) {
    int ans = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
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
        cin >> n;
        h.resize(n);
        for (int i = 0; i < n; i++)
            cin >> h[i];
        cout << bs(1, 1e9) << '\n';
    }
    return 0;
}