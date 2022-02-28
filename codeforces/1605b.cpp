#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        string s;
        int n;
        cin >> n >> s;
        vector < int > cnt(n);
        for (int i = 0; i < n; i++)
            cnt[i] += s[i] == '1';

        for (int i = 1; i < n; i++)
            cnt[i] += cnt[i - 1];
        
        int cnt0 = 0;
        vector < int > ans;
        for (int i = n - 1; i >= 0; i--) {
            cnt0 += (s[i] == '0');
            int cnt1 = (i == 0 ? 0 : cnt[i - 1]);
            // cout << i << " " << cnt0 << " " << cnt1 << endl;
            if (cnt0 == cnt1 && cnt1 > 0) {
                for (int j = 0; j <= i; j++)
                    if (s[j] == '1') ans.push_back(j);
                
                for (int j = i; j < n; j++)
                    if (s[j] == '0') ans.push_back(j);
                break;
            }
        }
        cout << (ans.size() != 0) << '\n';
        if (ans.size() > 0) {
            cout << ans.size() << " ";
            for (int pos : ans) cout << pos + 1 << " ";
            cout << '\n';
        }
    }
    return 0;
}