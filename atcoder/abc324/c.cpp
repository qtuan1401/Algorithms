#include <bits/stdc++.h>

using namespace std;

bool compare(string s, string t) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != t[i]) {
            t.erase(i, 1);
            return s == t;
        }
    }

    return true;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    while (tests--) {
        int n;
        string t;
        cin >> n >> t;
        int lenT = t.size();
        vector < int > ans;
        for (int k = 0; k < n; k++) {
            string s;
            cin >> s;
            int len = s.size();
            bool ok = false;
            if (s.size() == t.size()) {
                if (s == t) ok = true;
                else {
                    for (int i = 0; i < lenT; i++) {
                        if (s[i] != t[i]) {
                            s[i] = t[i];
                            break;
                        } 
                    }

                    if (s == t) ok = true;
                }
            } else if (len + 1 == lenT) {
                ok = compare(s, t);
            } else if (lenT + 1 == len) {
                ok = compare(t, s);
            }

            if (ok) ans.push_back(k + 1);
        }

        cout << ans.size() << '\n';
        for (auto & e : ans) cout << e << " ";
    }
    return 0;
}