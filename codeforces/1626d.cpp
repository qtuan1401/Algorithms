#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

vector < long long > sum;

long long bs(int l, int r, long long t) {
    int pos = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        // cout << l << " " << r << " " << mid << endl;
        if (sum[mid] <= t) {
            pos = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    return pos;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector < int > a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a.begin(), a.end());
        vector < int > b;
        vector < int > c;
        b.push_back(a[0]);
        c.push_back(1);
        for (int i = 1; i < n; i++) {
            if (a[i] == b.back())
                c.back()++;
            else {
                b.push_back(a[i]);
                c.push_back(1);
            }
        }
        n = b.size();
        sum.resize(n, 0);
        sum[0] = c[0];
        for (int i = 1; i < n; i++)
            sum[i] = sum[i - 1] + c[i];
        long long sum3 = 0, ans = INF;
        for (int i = 0; i < 40; i++) {
            if ((1ll << i) >= sum[n - 1])
                ans = min(ans, (1ll << i) - sum[n - 1] + 2);
        }
        for (int i = n - 1; i >= 0; i--) {
            long long ans1 = INF, ans2 = INF, ans3 = INF;
            for (int j = 0; j < 40; j++) {
                if ((1ll << j) >= sum3) {
                    ans3 = (1ll << j) - sum3;
                    break;
                }
            }
            for (int j = 0; j < 40; j++) {
                long long pos = bs(0, i, 1ll << j);
                long long sum1 = 0, sum2 = 0;
                if (pos == -1) {
                    sum2 = sum[pos];
                } else {
                    sum1 = sum[pos];
                    sum2 = sum[i] - sum[pos];
                }
                ans1 = (1ll << j) - sum1;
                for (int z = 0; z < 40; z++) {
                    if ((1ll << z) >= sum2) {
                        ans2 = (1ll << z) - sum2;
                        break;
                    }
                }
                ans = min(ans, ans1 + ans2 + ans3);
            }
            sum3 += c[i];
            // cout << i << " " << ans << endl;
        }
        cout << ans << '\n';
    }
    return 0;
}