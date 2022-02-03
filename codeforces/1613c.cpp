#include <bits/stdc++.h>

using namespace std;

vector < int > a;

bool check(long long x, int n, long long h) {
    long long cur = 0;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        if (cur >= a[i])
            sum += a[i] + x - 1 - cur;
        else
            sum += x;
        cur = a[i] + x - 1;
    }
    return sum >= h;
}

long long bs(long long l, long long r, int n, long long h) {
    long long ans = 0;
    while (l <= r) {
        long long mid = (l + r) / 2;
        if (check(mid, n, h)) {
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    return ans;
}

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        long long h;
        cin >> n >> h;
        a.resize(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cout << bs(1, 1e18, n, h) << '\n';
        a.clear();
    }
    return 0;
}