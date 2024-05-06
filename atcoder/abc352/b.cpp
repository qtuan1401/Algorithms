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
    int tests = 1;
    while (tests--) {
        string s, t;
        cin >> s >> t;
        int n = s.size(), m = t.size();
        for (int i = 0, j = 0; i < n && j < m; j++) {
            if (s[i] == t[j]) {
                cout << j + 1 << " ";
                i++;
            } 
        }
    }
    return 0;
}