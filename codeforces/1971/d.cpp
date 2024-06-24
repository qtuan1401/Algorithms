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
        string t;
        cin >> t;
        string s = "";
        s += t[0];
        for (int i = 1; i < t.size(); i++)
            if (s.back() != t[i]) s += t[i];
        int ans = 1, l = 2, n = s.size();
        if (n == 1) {
            cout << "1\n";
            continue;
        }
        if (s == "10") {
            cout << "2\n";
            continue;
        }
        if (s[0] == '1') ans++, l++;
        cout << ans + n - l << '\n';

    }
    return 0;
}

// 101