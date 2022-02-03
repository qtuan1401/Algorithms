#include <bits/stdc++.h>

using namespace std;


const int MAXN = 2e3 + 10;

struct node {
    int r1, c1, r2, c2;
    node(int _r1 = 0, int _c1 = 0, int _r2 = 0, int _c2 = 0) {
        r1 = _r1;
        c1 = _c1;
        r2 = _r2;
        c2 = _c2;
    } 
};

int T;
string s[MAXN];

int main() {
    //freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> T;
    for(int tests = 1; tests <= T; tests++) {
        int n, m;
        cin >> n >> m;
        for(int i = 0; i < n; i++)
            cin >> s[i];
        bool ok = true;
        int last = -1;
        vector < node > ans;
        for(int c = 0; c < 26; c++) {
            int cnt = 0;
            int pos = -1;
            for(int i = 0; i < n; i++)
                for(int j = 0; j < m; j++)
                    cnt += (c == s[i][j] - 'a');
            //check row
            for(int i = 0; i < n; i++) {
                int sum = 0;
                for(int j = 0; j < m; j++)
                    sum += (c == s[i][j] - 'a');
                if (sum == cnt && sum > 0) {
                    pos = i;
                    break;
                }
            }
            if (cnt > 0)
                last = c;
            else {
                ans.push_back(node(-1, -1, -1, -1));
                continue;
            }
        //    cout << cnt << endl;
            //check col
            if (pos == -1) {
                for(int j = 0; j < m; j++) {
                    int sum = 0;
                    for(int i = 0; i < n; i++)
                        sum += (c == s[i][j] - 'a');
                    if (sum == cnt) {
                        pos = j;
                        break;
                    }
                }
                if (pos == -1)
                    ok = false;
                else if (pos > -1) {
                    int l = n + 1, r = 0;
                    for(int i = 0; i < n; i++)
                        if (c == s[i][pos] - 'a') {
                            l = min(l, i);
                            r = max(r, i);
                        }
                    int mn = 30;
                    for(int i = l; i <= r; i++)
                        mn = min(mn, s[i][pos] - 'a');
                    if (mn < c) {
                        ok = false;
                        break;
                    } else 
                        ans.push_back(node(l, pos, r, pos));
                }
            } else {
                int l = m + 1, r = 0;
                for(int i = 0; i < m; i++)
                    if (c == s[pos][i] - 'a') {
                        l = min(l, i);
                        r = max(r, i);
                    }
                int mn = 30;
                for(int i = l; i <= r; i++)
                    mn = min(mn, s[pos][i] - 'a');
                if (mn < c) {
                    ok = false;
                    break;
                } else ans.push_back(node(pos, l, pos, r));
            }
         //   cout << c << endl;
        //    cout << ans[c].r1 << " " << ans[c].c1 << " " << ans[c].r2 << " " << ans[c].c2 << endl;
        }
        if (!ok) {
            cout << "NO\n";
            continue;
        }
        //cout << last << endl;
        cout << "YES\n";
        cout << last + 1 << '\n';
        for(int i = 0; i < ans.size(); i++)
            if ((ans[i].r1 == -1 || ans[i].c1 == -1) && i < last)
                cout << ans[last].r1 + 1 << " " << ans[last].c1 + 1 << " " << ans[last].r2 + 1 << " " << ans[last].c2 + 1 << '\n';
            else if (i <= last) cout << ans[i].r1 + 1 << " " << ans[i].c1 + 1 << " " << ans[i].r2 + 1 << " " << ans[i].c2 + 1 << '\n';
    }
}