#include <bits/stdc++.h>

using namespace std;

int n, k;
long long ans, res;
int dd[1005];

int main() {
    //freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    int len = (n & 1) + (n >> 1);
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        dd[x]++;
    }
    for(int i = 1; i <= k; i++) {
        res += dd[i] / 2;
        dd[i] = dd[i] & 1;
    }
    if (res >= len) 
        ans = len * 2;
    else {
        ans = res * 2;
        for(int i = 1; i <= k && res < len; i++) 
            res += dd[i], ans += dd[i];
    }
    cout << ans;
    return 0;
}