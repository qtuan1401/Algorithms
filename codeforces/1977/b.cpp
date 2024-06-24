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
        int x;
        cin >> x;
        // cout << x << endl;
        vector < int > bits(32, 0);
        int cnt = 0;
        while (x > 0) {
            bits[cnt] = x % 2;
            x /= 2;
            cnt++;
        }

        // for (int i = 0; i < 32; i++) cout << bits[i] << " ";
        // cout << '\n';

        for (int i = 0; i < 30; i++) {
            if (bits[i] == 1) {
                int j = i;
                while (bits[j + 1] == 1) j++;
                if (j != i) {
                    bits[j + 1] = 1;
                    bits[i] = -1;
                    for (int k = i + 1; k <= j; k++) bits[k] = 0;
                }
            }
        }

        cout << 32 << '\n';
        for (int i = 0; i < 32; i++) cout << bits[i] << " ";
        cout << '\n';
    }
    return 0;
}