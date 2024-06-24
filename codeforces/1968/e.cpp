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
        int n;
        cin >> n;
        if (n == 2) {
            cout << "1 1\n";
            cout << "1 2\n";
        } else if (n == 3) {
            cout << "2 1\n";
            cout << "2 3\n";
            cout << "3 1\n";
        } else {
            vector < pii > loc;
            for (int i = 0; i < n; i++) {
                loc.push_back(pii(i, 0));
            }
            for (int i = 1; i < n; i++) {
                loc.push_back(pii(n - 1, i));
            }

            string target = "1100101";
            for (int i = 4; i < n; i++) {
                target += "01";
            }
            
            // cout << target << endl;
            for (int i = 0; i < 2 * n - 1; i++) {
                if (target[i] == '1') cout << loc[i].first + 1 << " " << loc[i].second + 1 << '\n';
            }
        }
    }
    return 0;
}