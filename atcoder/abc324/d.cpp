#include <bits/stdc++.h>

using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    while (tests--) {
        int n;
        string s;
        cin >> n >> s;
        vector < int > digits;
        for (int i = 0; i < n; i++) digits.push_back(s[i] - '0');

        sort(digits.begin(), digits.end());
        
        long long ans = 0;
        for (long long i = 0; i <= 10000000; i++) {
            long long k = i * i;
            vector < int > d;
            while (k > 0) {
                d.push_back(k % 10);
                k /= 10;
            }
            if (d.size() > n) break;

            while (d.size() < n) d.push_back(0);

            sort(d.begin(), d.end());

            bool ok = true;
            for (int j = 0; j < n; j++) {
                if (digits[j] != d[j]) {
                    ok = false;
                    break;
                }
            }

            ans += ok;
        }
        cout << ans << '\n';
    }
    return 0;
}