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
        long long x;
        cin >> x;
        vector < int > digits;
        while (x > 0) {
            digits.push_back(x % 10);
            x /= 10;
        }
        if (digits.back() > 1) {
            cout << "NO\n";
            continue;
        }
        bool ok = true;
        int n = digits.size();
        for (int i = 0; i < n - 1; i++) {
            bool found = false;
            int cur = digits[i] - (i != 0);
            for (int a = 5; a <= 9; a++) {
                for (int b = 5; b <= 9; b++) {
                    int sum = (a + b) % 10;
                    if (sum == cur) {
                        found = true;
                    }
                }
            }
            if (!found) {
                ok = false;
                break;
            }
        }

        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}