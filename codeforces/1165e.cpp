#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;
const int md = 2e5 + 10;

typedef pair < int, int > II;

struct node {
    long long val, id, t;
};

long long a[md], cnt[md];
long long b[md];
int n;


int main() {
    //freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] *= 1ll * i * (n - i + 1);
    }
    for(int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + n);
    long long res = 0;
    for(int i = 1; i <= n; i++)
        res = (res + ((a[i] % mod * b[n - i + 1]) % mod)) % mod;

    cout << res;
    return 0;
}