#include <bits/stdc++.h>

using namespace std;

long long getBit(long long x, long long i) {
    return (x >> i) & 1;
}

long long calc(vector < long long > & a, long long x) {
    long long ans = 0;
    int n = a.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 32; j++) {
            if (getBit(x, j) == 0 && getBit(a[i], j) == 1) return ans;
        }
        ans |= a[i]; 
    }
    return ans;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests;
    cin >> tests;
    while (tests--) {
        int n, x;
        cin >> n >> x;
        vector < long long > a(n), b(n), c(n);

        long long cur = 0;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        for (int i = 0; i < n; i++) cin >> c[i];

        cur |= calc(a, x);
        cur |= calc(b, x);
        cur |= calc(c, x);

        if (cur == x) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}