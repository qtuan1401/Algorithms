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
        string s;
        cin >> s;
        int n = s.size();

        int cnt = 0;
        for (int i = 0; i < n; i++) cnt += s[i] == '0';

        long long ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0' && i + 1 > cnt) {
                ans += i + 1 - cnt + 1;
                cnt--;
            }
        }

        cout << ans << '\n';
    }
    return 0;
}