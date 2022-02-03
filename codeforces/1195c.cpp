#include <bits/stdc++.h>

using namespace std;

const int md = 1e5 + 10;

int a[md], b[md];
long long f[md][2];
int n;

int main() {
//    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++) 
        cin >> a[i]; 
    for(int i = 1; i <= n; i++) 
        cin >> b[i]; 
    for(int i = 1; i <= n; i++) {
        f[i][0] = max(f[i - 1][0], f[i - 1][1] + b[i]);
        f[i][1] = max(f[i - 1][1], f[i - 1][0] + a[i]);
    }
    cout << max(f[n][0], f[n][1]);
    return 0;
}