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
        string s;
        cin >> s;
        int n = s.size();
        int cntL = 0, cntU = 0;
        for (int i = 0; i < n; i++) {
            if ('a' <= s[i] && s[i] <= 'z') cntL++;
            else cntU++;
        }

        if (cntL > cntU) {
            for (int i = 0; i < n; i++) s[i] = tolower(s[i]);
        } else {
            for (int i = 0; i < n; i++) s[i] = toupper(s[i]);
        }

        cout << s << '\n';
    }
    return 0;
}