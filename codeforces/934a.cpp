#include <bits/stdc++.h>

using namespace std;

int n, m;
long long a[55], b[55];

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < m; i++)
        cin >> b[i];
    long long ans = 1e18;
    for(int i = 0; i < n; i++) {
        long long mul = -1e18;
        for(int j = 0; j < m; j++)
            for(int k = 0; k < n; k++)
                if (k != i)
                    mul = max(mul, a[k] * b[j]);
        ans = min(ans, mul);
    }
    cout << ans;
    return 0;
}