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

const long long MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    while (tests--) {
        int n;
        string s;
        cin >> n >> s;
        long long ans = 1;
        int cnt = 1;
        s += s.back();
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1]) {
                ans *= cnt / 2 + 1 - (cnt % 2 == 0);
                ans %= MOD;
                cnt = 1;
            } else cnt++;
        }
        cout << ans << '\n';
    }
    return 0;
}