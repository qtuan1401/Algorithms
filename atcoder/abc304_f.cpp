#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;
const int LIM = 2e5;

vector < int > pp;

string s;

int calc(int x) {
    int ans = x;
    map < int, int > mp;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '.') {
            if (mp[i % x] == 0) ans--;
            mp[i % x] = 1;
        }
    }
    return pp[ans];
}

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    pp.resize(LIM + 1);
    pp[0] = 1;
    for (int i = 1; i <= LIM; i++) {
        pp[i] = pp[i - 1] * 2;
        pp[i] %= MOD;
    }

    while (tests--) {
        int n;
        cin >> n >> s;
        int ans = 0;
        vector < int > cnt(n + 1);
        for (int i = 1; i * i < n; i++) {
            if (n % i == 0) {
                cnt[i] = calc(i);
                int x = n / i;
                if (x == n || x== i) continue;
                cnt[x] = calc(x);
            } 
        }

        for (int i = 1; i <= n; i++) {
            for (int j = i * 2; j <= n; j += i) {
                if (cnt[j] != 0)
                    cnt[j] = (cnt[j] - cnt[i] + MOD) % MOD;
            }
        }


        for (int i = 1; i <= n; i++) {
            ans += cnt[i];
            ans %= MOD;
        }
        cout << ans << '\n';
    }
    return 0;
}