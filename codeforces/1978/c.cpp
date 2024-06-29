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
        long long k;
        cin >> n >> k;
        if (k & 1) {
            cout << "No\n";
            continue;
        }
        vector < int > a(n, 0);
        for (int i = 0; i < n; i++) a[i] = i;
        for (int i = 0, j = n - 1; i < n; i++) {
            if (k >= (j - i) * 2) {
                k -= (j - i) * 2;
                swap(a[i], a[j]);
                j--;
                if (k <= 0) break;
            }
        }

        if (k == 0) {
            cout << "Yes\n";
            for (int i = 0; i < n; i++) cout << a[i] + 1 << " ";
            cout << '\n';
        } else {
            cout << "No\n";
            continue;
        }
    }
    return 0;
}