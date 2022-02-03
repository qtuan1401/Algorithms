#include <bits/stdc++.h>

using namespace std;

int n, odd;
int cnt[100];
string s, ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    cin >> s;
    //cout << s << "*";
    for(int i = 0; i < n; i++) 
        cnt[s[i] - 'a']++;
    ans = s;
    for(int i = 0; i < 26; i++)
        odd += (cnt[i] % 2 == 1);
    //cout << odd << endl;
    int len = n - odd - 1, pos = 0;
    for(int i = 0; i < 26; i++) {
        for(int j = 0; j < cnt[i] / 2; j++) {
            ans[len - pos] = ans[pos] = char(i + 'a');
            pos++;
        }
    }
    
    for(int i = 0; i < 26; i++)
        if (cnt[i] % 2 == 1)
            ans[++len] = char(i + 'a');
    
    cout << ans;
    return 0;
}