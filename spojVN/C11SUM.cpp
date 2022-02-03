#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;

long long res, m, temp, n;
char s[int(1e6 + 10)];

int main() {
//	freopen("test.inp", "r", stdin);
	//freopen("test.inp", "r", stdin);
	//ios_base::sync_with_stdio(0);
	scanf("%s", s);
	n = strlen(s) - 1;
	temp = 1;
	for(int i=n;i>=0;i--) {
		res = (res + (long long)(s[i] - '0') * (i + 1) * temp) % mod;
		//cout << (i + 1) * (temp) << endl;
		//cout << res << endl;
		temp = ((temp * 10) + 1) %  mod;
	}

	printf("%lld", res);
	return 0;
}