#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        long long n, k;
        cin >> n >> k;
        n--;
        long long tot = 1;
        long long res = 0;
        while (tot < k && n > 0) {
            n -= tot;
            tot *= 2;
            res++;
        }

        res += n / k + (n % k > 0);
        cout << res << '\n';
    }
    return 0;
}