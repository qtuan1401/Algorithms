#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int cnt[26];

int main() {
    ios_base::sync_with_stdio(0);
    string s;
    int n;
    cin >> n >> s;
    int mx = 0;
    for(int i = 0; i < n; i++) {
        cnt[s[i] - 'A']++;
        mx = max(mx, cnt[s[i] - 'A']);
    }
    int res = 0;
    for(int i = 0; i < 26; i++)
        res += (cnt[i] == mx);
    int ans = 1;
    for(int i = 0; i < n; i++) 
        ans = (1ll * ans * res) % MOD;
    cout << ans;
	return 0;
}