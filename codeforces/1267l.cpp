#include <bits/stdc++.h>

using namespace std;

int n, l, k;
string s;
string ans[1005];

int main() {
    ios_base::sync_with_stdio(0);
    //freopen("test.in", "r", stdin);
    cin >> n >> l >> k;
    cin >> s;
    sort(s.begin(), s.end());
    int pos = 1, id = 0;
    for(int i = 1; i <= l; i++) {
        int nxt = 1;
        for(int j = pos; j <= k; j++) {
            ans[j] += s[id++];
            if (ans[j].size() != ans[j - 1].size() || ans[j][i - 1] != ans[j - 1][i - 1])
                nxt = j;
        }
        //cout << i << " " << nxt << endl;
        pos = nxt;
    }

    for(int i = 1; i <= n; i++)
        while (ans[i].size() < l) 
            ans[i] += s[id++];
        
    for(int i = 1; i <= n; i++)
        cout << ans[i] << '\n';
    return 0;
}