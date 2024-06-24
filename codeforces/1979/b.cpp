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

int getBit(int x, int i) {
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
        int x, y;
        cin >> x >> y;
        if (x < y) swap(x, y);
        int mx = 0;
        for (int i = 0; i < 30; i++)
            if (getBit(x, i) != getBit(y, i)) {
                mx = i;
                break;
            }

        cout << (1 << mx) << '\n';
    }
    return 0;
}