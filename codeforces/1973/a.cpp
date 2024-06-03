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

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests;
    cin >> tests;
    while (tests--) {
        vector < int > a(3, 0);
        cin >> a[0] >> a[1] >> a[2];
        int sum = a[0] + a[1] + a[2];
        if (sum & 1) {
            cout << "-1\n";
            continue;
        }

        cout << min(a[0] + a[1], sum / 2) << '\n';
    }
    return 0;
}