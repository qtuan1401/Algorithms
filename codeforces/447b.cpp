#include <bits/stdc++.h>

using namespace std;

string s;
int n, k;
int w[26];

int main() {
    ios_base::sync_with_stdio(0);
    cin >> s;
    int n = s.size();
    cin >> k;
    int mx = 0;
    for(int i = 0; i < 26; i++)
        cin >> w[i], mx = max(mx, w[i]);
    long long res = 0;
    for(int i = 0; i < n; i++)
        res += w[s[i] - 'a'] * (i + 1);
    for(int i = n; i < n + k; i++)
        res += mx * (i + 1);
    cout << res;
    return 0;
}