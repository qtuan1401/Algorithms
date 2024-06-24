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
        int n;
        cin >> n;
        vector < int > a(n, 0);
        a[0] = 0;
        for (int i = 1; i < n; i++) {
            cin >> a[i];
            a[0] = max(a[0], a[i]);
        }
        a[0] += 1;
        cout << a[0] << " ";
        for (int i = 1; i < n; i++) {
            a[i] += a[i - 1];
            cout << a[i] << " "; 
        }
        cout << '\n';
    }
    return 0;
}