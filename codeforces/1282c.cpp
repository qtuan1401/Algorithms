#include <bits/stdc++.h>

using namespace std;

const int md = 2e5 + 10;

pair < int, int > t[md];
int a, b, n, T;

int calc(int x, int pa, int pb) {
    if (1ll * pa * a > x) 
        return x / a;
    else {
        x -= pa * a;
        return min(x / b, pb) + pa; 
    }
}

int main() {
    //freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tests;
    cin >> tests;
    while (tests--) {
        cin >> n >> T >> a >> b;
        int cnt0 = 0, cnt1 = 0;
        for(int i = 1; i <= n; i++) {
            cin >> t[i].second;
            cnt0 += (t[i].second == 0);
        }
        cnt1 = n - cnt0;
        for(int i = 1; i <= n; i++) 
            cin >> t[i].first;
        sort(t + 1, t + 1 + n);
        t[n + 1].first = T + 1;
        int c0 = 0, c1 = 0;
        int res = calc(t[1].first - 1, cnt0, cnt1);
        for(int i = 1; i <= n; i++) {
            c0 += (t[i].second == 0);
            c1 += (t[i].second == 1);
            if (t[i].first == t[i + 1].first)
                continue;
            int ans = 0, lim = t[i + 1].first - 1;
            long long temp = 1ll * c0 * a + 1ll * c1 * b;
            if (temp > lim)
                ans = 0;
            else ans = c0 + c1 + calc(lim - temp, cnt0 - c0, cnt1 - c1);
            res = max(res, ans);
        }
        cout << res << '\n';
    }
    return 0;
}