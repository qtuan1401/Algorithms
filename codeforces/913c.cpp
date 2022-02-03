#include <bits/stdc++.h>

using namespace std;

long long a[35];
int n, l;

int getBit(int x, int i) {
    return ((x >> i) & 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> l;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 1; i < n; i++)
        a[i] = min(a[i - 1] * 2, a[i]);
    
    for(int i = n; i <= 30; i++)
        a[i] = a[i - 1] * 2;

    long long res = 0;
    
    long long ans = 1e18;
    for(int i = 30; i >= 0; i--)
        if (getBit(l, i))
            res += a[i];
        else 
            ans = min(ans, res + a[i]);
    
    cout << min(ans, res);
    return 0;
}