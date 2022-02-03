#include <bits/stdc++.h>

using namespace std;

const int md = 2e5 + 10;

int t, n;
set < string > v[5];
string s[md];

int main() {
    //freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        if (n == 0) {
            cout << '\n';
            continue;
        }
        v[0].clear(); v[1].clear();
        int cnt00 = 0, cnt01 = 0, cnt10 = 0, cnt11 = 0;
        for(int i = 0; i < n; i++) {
            cin >> s[i];
            if (s[i][0] == '0') {
                if (s[i].back() == '1')
                    v[0].insert(s[i]);
                else cnt00++;
            } else {
                if (s[i].back() == '0')
                    v[1].insert(s[i]);
                else cnt11++;
            }
        }
        vector < int > ans;
        cnt01 = v[0].size(); cnt10 = v[1].size();
        if (cnt00 > 0 && cnt11 > 0 && cnt01 == 0 && cnt10 == 0) {
            cout << "-1\n";
            continue;
        } else {
            if (cnt01 > cnt10 + 1) {
                for(int i = 0; i < n; i++)
                    if (s[i][0] == '0' && s[i].back() == '1') {
                        string s1 = s[i];
                        reverse(s1.begin(), s1.end());
                        if (v[1].count(s1) == 0) 
                            ans.push_back(i + 1);
                    }
            } else if (cnt10 > cnt01 + 1) {
                for(int i = 0; i < n; i++)
                    if (s[i][0] == '1' && s[i].back() == '0') {
                        string s1 = s[i];
                        reverse(s1.begin(), s1.end());
                        if (v[0].count(s1) == 0)
                            ans.push_back(i + 1);
                    }
            }
            int mx = (max(cnt10, cnt01) - min(cnt01, cnt10)) / 2;
            cout << mx << '\n';
            for(int i = 0; i < mx; i++)
                cout  << ans[i] << " ";
            cout << '\n';
        }
    }
    return 0;
}