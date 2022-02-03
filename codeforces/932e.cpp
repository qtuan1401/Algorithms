#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MXN = 5e3 + 10;

int dp[MXN][MXN];
int n, k;

long long calcPow(long long a, long long n) {
    long long res = 1;
    while (n > 0) {
        if (n & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        n /= 2;
    }
    return res;
}

int f(int diffs, int a){
	if (dp[diffs][a] >= 0)
        return dp[diffs][a];

	int b = n - a;

	if (diffs == 0)
		return dp[diffs][a] = calcPow(2, b);
	
	return dp[diffs][a] = ((b ? 1LL * b * f(diffs - 1, a + 1) : 0LL) + (a ? 1LL * a * f(diffs - 1, a) : 0LL)) % MOD;
}

int main() {
	ios_base::sync_with_stdio(false); 
    cin >> n >> k;
    memset(dp, -1, sizeof(dp));
    cout << f(k, 0);
	return 0;
}