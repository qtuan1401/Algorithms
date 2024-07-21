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

void calc(long long & n, long long l, long long r, int type) {
    long long num = r - l + 1;
    if (n > num) n -= num;
    else {
        l += n - 1;
        cout << l;
        if (type == 0) {
            l /= 10;
        }
        while (l > 0) {
            cout << l % 10;
            l /= 10;
        }
        cout << '\n';
        n = 0;
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    freopen("../test.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    while (tests--) {
        long long n;
        cin >> n;
        if (n <= 10) {
            cout << n - 1 << '\n';
            continue;
        } else if (n <= 19) {
            n -= 10;
            cout << n * 10 + n << '\n';
            continue;
        }
        n -= 19;
        long long tot = 0;
        long long l = 10, r = 99;
        for (int i = 0; i < 18; i++) {
            calc(n, l, r, 0);
            if (n == 0) break;
            calc(n, l, r, 1);
            if (n == 0) break;
            l *= 10;
            r = l * 10 - 1;
        }
    }
    return 0;
}