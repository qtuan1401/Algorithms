#include <bits/stdc++.h>

using namespace std;

template < class T >
void resetVec(vector < T > & a, int sz, T val) {
    a.clear();
    a.resize(sz, val);
}

const long long LIM = 1e8;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    while (tests--) {
        int n;
        cin >> n;
        // cout << n << endl;
        vector < long long > a(n + 1, 0);
        
        long long sum1 = 0, ans = 0, sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }
        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());

        // for (int i = 0; i < n; i++) {
        //     long long sum = 0;
        //     for (int j = i + 1; j < n; j++) {
        //         sum += (a[i] + a[j]) % LIM;
        //     }
        //     cout << sum << endl;
        // }
        a[n + 1] = 0;
        int l = n - 1;
        for (int i = 0; i < n; i++) {
            sum -= a[i];
            if (l <= i) {
                ans += a[i] * (n - i - 1) + sum;
                continue;
            }
            while (l > i && a[l] + a[i] < LIM) {
                sum1 += a[l];
                l--;
            }
            long long sum2 = sum - sum1;
            long long smaller = sum1 + a[i] * (n - l - 1);
            long long bigger = sum2 - LIM * (l - i) + 1ll * a[i] * (l - i);
            ans += smaller + bigger;
        }
        cout << ans << '\n';
    }
    return 0;
}