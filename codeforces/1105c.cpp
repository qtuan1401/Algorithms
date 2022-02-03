#include <bits/stdc++.h>

using namespace std;

const int MXN = 2e5 + 10;
const int MOD = 1e9 + 7;

int f[MXN][3], cnt[3], n, l, r;
int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> l >> r;
	cnt[0] = r / 3 - (l - 1) / 3;
	cnt[1] = (r + 2) / 3 - (l + 1) / 3;
	cnt[2] = (r + 1) / 3 - l / 3;
	f[0][0] = 1;
	for(int i = 1; i <= n; i++)
	    for(int j = 0; j < 3; j++)
		    for(int k = 0; k < 3; k++)
		        f[i][j] = (1ll * f[i][j] + 1ll * f[i - 1][(j + k) % 3] * cnt[k]) % MOD;
	cout << f[n][0];
	return 0;
}