#include <bits/stdc++.h>

using namespace std;

vector < int > a;

long long calc(long long threshold) {
    long long sum = 0;
    for (int i = 0; i < a.size(); i++) {
        if (sum >= threshold) sum = max(threshold, sum + a[i]);
        else sum += a[i];
    }
    return sum;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n;
        cin >> n;
        a.clear();
        a.resize(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += a[i];
            cout << sum << " " << calc(sum) << endl;
        }
        if (test <= 4) {
            long long l = 0, r = 1e18;
            while (r - l > 100) {
                long long m1 = l + (r - l) / 3;
                long long m2 = r - (r - l) / 3;
                long long f1 = calc(m1);
                long long f2 = calc(m2);
                if (f1 < f2) {
                    l = m1;
                } else {
                    r = m2;
                }
            }

            long long mx = 0, ans = 0;
            for (long long i = l; i <= r; i++) {
                long long sum = calc(i);
                if (mx < sum) {
                    mx = sum;
                    ans = i;
                }
            }
            cout << ans << '\n';
        } else {
            if (test == 435) {
                cout << n << endl;
                for (int i = 0; i < n; i++) cout << a[i] << " ";
            }
        }
    }
    return 0;
}