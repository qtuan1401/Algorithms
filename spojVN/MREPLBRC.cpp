#include <bits/stdc++.h>

using namespace std;

const int md = 2e2 + 10;
const int mod = 1e5;

int dp[md][md];
string s;
bool kt = false;
int n;

int get(int i, int j) {
//	cout << s[i] << " " << s[j] << endl;
	if (s[i] == '(' && (s[j] == '?' || s[j] == ')'))
		return 1;
	if (s[i] == '[' && (s[j] == '?' || s[j] == ']'))
		return 1;
	if (s[i] == '{' && (s[j] == '?' || s[j] == '}'))
		return 1;
	if (s[i] == '?' && (s[j] == ')' || s[j] == ']' || s[j] == '}'))
		return 1;
	if (s[i] == '?' && s[j] == '?')
		return 3;
	return 0;
}

long long f(int l, int r) {
	if (l > r)
		return 1;
	if (dp[l][r] != -1)
		return dp[l][r];

	long long res = 0;
	for(int k=l+1;k<=r;k++) {
		long long s1 = f(l + 1, k - 1);
		long long s2 = f(k + 1, r);
		if (get(l, k) * s1 * s2 >= mod)
			kt = true;
		res = (res % mod + (get(l, k) * (s1 % mod * s2 % mod) % mod) % mod) % mod;
	}
	return dp[l][r] = res;
}

int main() {
//	freopen("test.inp", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin >> n;
	cin >> s;
	s = "#" + s;
	memset(dp, -1, sizeof(dp));
	long long res = f(1, n);
	int len;
    if (!res)
        len = 1;
    else
        len = log(res);
	if (kt)
		for(int i=1;i<=5-len;i++)
			cout << 0;
	cout<<res;
	return 0;
}
