#include <bits/stdc++.h>

using namespace std;

string s;
long long res = 0;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> s;
    int n = s.size();
    for(int i = 0; i < n; i++) {
        int r = n;
        for(int j = i; j <= min(n, i + 9); j++)
            for(int len = 1; len <= 9; len++) {
                if (i + 2 * len >= n)
                    break;
                if (s[j] == s[j + len] && s[j + len] == s[j + len * 2])
                    r = min(r, j + len * 2);
            }
        //cout << i << " " << r << " " << 1ll * (i + 1) * (n - 1 - r + 1) << endl;
        res += (n - 1 - r + 1); 
    }   
    cout << res;
    return 0;
}