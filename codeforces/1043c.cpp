#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    vector < int > ans(s.size());
    fill(ans.begin(), ans.end(), 0);
    for (int i = 0; i < s.size(); i++)
        if (s[i] == 'a') {
            ans[i - 1] ^= 1;
            ans[i] = 1;
        }
    for (int i = 0; i < s.size(); i++)
        cout << ans[i] << " ";
    return 0;
}