#include <bits/stdc++.h>

using namespace std;

const int MXN = 1e5+10;

int n, res;
int dp[MXN], p[MXN], x[MXN];

int main() {
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    for(int i = 2; i <= n; i++)
        cin >> p[i];
    for(int i = 2; i <= n; i++) {
        dp[i] = 1 + dp[p[i]];
        x[dp[i]]++;
    }
    
    for(int i = 0; i <= n; i++)
        res += x[i] % 2;
    cout << res + 1;
}