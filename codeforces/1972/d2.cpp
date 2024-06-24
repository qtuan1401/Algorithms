#include <bits/stdc++.h>

using namespace std;

template < class T >
void resetVec(vector < T > & a, int sz, T val) {
    a.clear();
    a.resize(sz, val);
}

typedef long double ld;
typedef long long ll;
typedef pair < int, int > pii;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);    
}

int eulerPhi(int n) {
    if (n == 0) return 0;
    int ans = n;
    for (int x = 2; x*x <= n; ++x) {
        if (n % x == 0) {
            ans -= ans / x;
            while (n % x == 0) n /= x;
        }
    }
    if (n > 1) ans -= ans / n;
    return ans;
}

const int LIM = 2e6;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests;
    cin >> tests;
    vector < long long > phi(LIM + 1, 0);
    for (int i = 1; i <= LIM; i++) phi[i] = eulerPhi(i);
    while (tests--) {
        int n, m;
        cin >> n >> m;
        long long ans = 0;
        for (int i = 2; i <= n; i++) {
            cout << i << " " << phi[i] << endl;
            ans += phi[i] * (n / i - 1);
        }
        for (int i = 2; i <= m; i++) {
            ans += phi[i] * (m / i - 1);
        }

        cout << ans << '\n';
    }
    return 0;
}