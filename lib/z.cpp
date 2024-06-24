// codeforces 1984d
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
 
vector < int > z;
int n;
 
void zFunc(string & s) {
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i < r) z[i] = min(r - i, z[i - l]);

        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;

        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    z[0] = n;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests;
    cin >> tests;
    while (tests--) {
        string s;
        cin >> s;
        string nas = "";
        int ca = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'a' && nas.size() == 0) {
                ca++;
                continue;
            }
            nas += s[i];
        }
        if (ca == s.size()) {
            cout << (int)s.size() - 1 << '\n';
            continue;
        }
        // cout << nas << endl;
        n = nas.size();
        vector < int > nxt(n, 0);
        int pre = n;
        for (int i = n - 1; i >= 0; i--) {
            if (nas[i] != 'a') pre = i;
            nxt[i] = pre;
        }
        resetVec(z, n, 0);
        zFunc(nas);
        vector < int > isValid(n, 0);
        for (int i = 0; i < n; i++) {
            bool ok = true;
            for (int j = i + 1; j < n; j += i + 1) {
                j = nxt[j];
                // cout << i << " " << j << endl;
                if (j == n) break;
                if (z[j] < i + 1) {
                    ok = false;
                    break;
                }
            }
 
            isValid[i] = ok;
        }
 
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            if (!isValid[i]) continue;
            int len = i + 1;
            int mn = ca;
            for (int j = i + 1; j < n; j += i + 1) {
                int prej = j;
                j = nxt[j];
                if (j == n) break;
                int diff = j - prej;
                mn = min(mn, diff); 
            }
            ans += mn + 1;
        }
        cout << ans << '\n';
    }
    return 0;
}