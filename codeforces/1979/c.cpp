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

long long getGcd(long long a, long long b) {
    if (b == 0) return a;
    return getGcd(b, a % b);
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests;
    cin >> tests;
    while (tests--) {
        int n;
        cin >> n;
        vector < long long > a(n);
        vector < long long > ans(n);
        long long mul = 1, sum = 0;
        for (int i = 0; i < n; i++) cin >> a[i];
        if (n >= *max_element(a.begin(), a.end())) {
            cout << "-1\n";
            continue;
        }

        long long lcm = a[0];
        for (int i = 1; i < n; i++) {
            lcm = (a[i] * lcm) / getGcd(a[i], lcm);
        }
        
        for (int i = 0; i < n; i++) {
            ans[i] = lcm / a[i];
            sum += ans[i];
        }

        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (sum >= ans[i] * a[i]) {
                ok = false;
                break;
            }
        }

        if (!ok) {
            cout << "-1\n";
            continue;
        }
        for (int i = 0; i < n; i++) cout << ans[i] << " ";
        cout << '\n';
    }
    return 0;
}