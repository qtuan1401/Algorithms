#include <bits/stdc++.h>

using namespace std;

const int LIM = 1e6;

vector < int > notPrime(LIM + 1);

void eratos(int n) {
    notPrime[1] = true;
    for (int i = 2; i * i <= n; i++)
        if (!notPrime[i])
            for (int j = i * i; j <= n; j += i)
                notPrime[j] = true;
}

int main() {
    // freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    eratos(LIM);

    int T;
    cin >> T;
    while (T--) {
        int n, e;
        cin >> n >> e;
        vector < int > a(n), sumL(n, 0), sumR(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sumR[i] = sumL[i] = a[i] == 1;
        }
        for (int i = 0; i < n; i++) {
            int pre = i - e;
            if (pre < 0 || a[i] != 1) continue;
            sumL[i] += sumL[pre];
        }

        for (int i = n - 1; i >= 0; i--) {
            int nxt = i + e;
            if (nxt >= n || a[i] != 1) continue;
            sumR[i] += sumR[nxt];
        }

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            if (notPrime[a[i]]) continue;
            int l = (i - e < 0 ? 0 : sumL[i - e]);
            int r = (i + e >= n ? 0 : sumR[i + e]);
            ans += 1ll * (l + 1) * (r + 1) - 1;
            // cout << ans << " " << l << " " << r << endl;;
        }

        cout << ans << '\n';
    }
    return 0;
}