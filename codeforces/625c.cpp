#include <bits/stdc++.h>

using namespace std;

const int MXN = 1e3 + 10;

int n, k, sum;
int ans[MXN][MXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
	int tot = n * n;
    for(int i = n; i >= 1; i--)
        for(int j = n; j >= k; j--) {
            ans[i][j] = tot--;
            if (j == k)
                sum += ans[i][j];
        }
    for(int i = n; i >= 1; i--)
        for(int j = k - 1; j >= 1; j--)
            ans[i][j] = tot--;
    cout << sum << '\n';
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++)
            cout << ans[i][j] << " ";
        cout << '\n';
    }
    return 0;
} 