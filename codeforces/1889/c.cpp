#include <bits/stdc++.h>

#define vall(a) (a.begin(), a.end())

using namespace std;

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
        string s;
        cin >> n >> s;
        if (n & 1) {
            cout << "-1\n";
            continue;
        }
        int l = 0, r = (int)s.size() - 1;

        int cnt = 0;

        bool ok = true;
        vector < int > ans;
        // cout << s << endl;
        while (l < r && ans.size() <= 300) {
            if (l == r) {
                ok = false;
                break;
            }
            // cout << l << " " << r << " " << s << endl;
            if (s[l] != s[r]) {
                l++;
                r--;
            } else {
                if (s[l] == '0') {
                    ans.push_back(r);
                    s.insert(r + 1, "01");
                    r += 1;
                    l++;
                } else {
                    ans.push_back(l);
                    s.insert(l, "01");
                    l++;
                    r += 1;
                }
            }
        }
        if (ans.size() > 300 || !ok) cout << "-1\n";
        else {
            cout << ans.size() << '\n';
            for (int & e : ans) cout << e + 1 << " ";
            cout << '\n'; 
        }
    }
    return 0;
}