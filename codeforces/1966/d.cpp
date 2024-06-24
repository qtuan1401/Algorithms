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
        int n, k;
        cin >> n >> k;
        if (n <= 10) {
            for (int i = 1; i < k; i++) cout << 1 << " ";
            for (int i = k + 1; i <= n; i++) cout << i << " ";
        } else {
            for (int i = 1; i <= 9; i++) cout << 1 << " ";
            
        }
    }
    return 0;
}