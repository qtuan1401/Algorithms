#include <bits/stdc++.h>

#define vall(a) (a.begin(), a.end())

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;

ll calcPow(ll a, ll n) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        n /= 2;
    }

    return res;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    while (tests--) {
        int n;
        cin >> n;
        vector < ll > a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        vector < ll > prop(n + 1);
        pp[0] = 1;
        for (int i = 1; i <= n; i++) prop[i] = 
    }
    return 0;
}