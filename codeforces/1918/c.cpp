#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair < int, int > pii;

long long flipBit(long long x, int i) {
    return x ^ (1ll << i);
}

int getBit(long long x, int i) {
    return (x >> i) & 1;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests;
    cin >> tests;
    while (tests--) {
        long long a, b, r;
        cin >> a >> b >> r;
        if (a > b) swap(a, b);
        long long cur = 0;
        for (int i = 63; i >= 0; i--) {
            if (getBit(a, i) == 0 && getBit(b, i) == 1 && flipBit(cur, i) <= r) {
                cur = flipBit(cur, i);
                a = flipBit(a, i);
                b = flipBit(b, i);
            }
        }
        // cout << cur << " " << a << " " << b << endl;
        cout << abs(b - a) << '\n';
    }
    return 0;
}