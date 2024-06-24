#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair < int, int > pii;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    while (tests--) {
        string s;
        cin >> s;
        int n = s.size();

        vector < char > stk;

        for (int i = 0; i < n; i++) {
            stk.push_back(s[i]);
            int x = stk.size();
            if (stk.size() >= 3 && stk[x - 3] == 'A' && stk[x - 2] == 'B' && stk[x - 1] == 'C') {
                stk.pop_back();
                stk.pop_back();
                stk.pop_back();
            }
        }

        for (char & c : stk) cout << c;
        cout << '\n';
    }
    return 0;
}