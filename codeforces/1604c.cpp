#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector < int > a(n);
        // cout << n << endl;
        long long lcm = 1;
        bool ok = true;
        for (int i = 1; i <= n; i++) {
            long long x;
            cin >> x;
            // cout << x << " ";
            if (lcm < 1000000000) lcm = (lcm * (i + 1)) / gcd(lcm, i + 1);
            if (x % lcm == 0) {
                ok = false;
            }
        }
        // cout << endl;
        if (ok) cout << "YES\n";
        else cout << "NO \n";
    }
    return 0;
}