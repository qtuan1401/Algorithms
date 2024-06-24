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
        cin >> n;
        vector < int > a(n);
        set < int > s;
        map < int, int > mp;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            s.insert(a[i]);
            mp[a[i]]++;
        }

        if (s.size() == 1) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            string ans = "";
            for (int i = 0; i < n; i++) ans += "R";
            int pos = 0;
            for (int i = 0; i < n; i++) 
                if (mp[a[i]] > 1) pos = i;
            ans[pos] = 'B';
            cout << ans << '\n';
        }
    }
    return 0;
}