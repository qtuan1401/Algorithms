#include <bits/stdc++.h>

using namespace std;

vector < long long > a;
long long sum;
int n;

bool check(long long x, long long avg) {
    long long remain = x * n + (n - sum % n) % n;
    long long median = a[(n - 1) / 2];
    for (int i = (n - 1) / 2 + 1; i < n; i++) {
        if (remain <= 0)
            break;
        long long len = i - (n - 1) / 2;
        long long diff = a[i] - a[i - 1];
        if (diff * len >= remain) {
            median += remain / len;
        } else {
            median += diff;
        }
        remain -= diff * len;
    }
    if (remain > 0)
        median += remain / (n - (n - 1) / 2);
    return median >= avg + x;
}

long long bs(long long l, long long r, long long avg) {
    long long ans = 0;
    while (l <= r) {
        long long mid = (l + r) / 2;
        if (check(mid, avg)) {
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        a.resize(n);
        sum = 0;
        for (int i = 0; i < n; i++)
            cin >> a[i], sum += a[i];
        sort(a.begin(), a.end());
        long long median = a[(n - 1) / 2];
        long long avg = (sum / n) + (sum % n != 0);
        long long res = (n - sum % n) % n;
        if (median >= avg) {
            cout << res + (median - avg) * n << '\n';
        } else {
            long long pos = bs(0, 1e9, avg);
            long long remain = pos * n + (n - sum % n) % n;
            cout << remain << '\n';
        }
    }
    return 0;
}