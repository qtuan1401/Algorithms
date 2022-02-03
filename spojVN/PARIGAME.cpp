#include <bits/stdc++.h>

using namespace std;

const int md = 5e2 + 10;

long long check[md][md], a[md][md];
long long f1[md][md], f2[md][md];
bool dp[md][md];
int n, q, t;

bool f(int i, int j) {
	if (i == 0 || j == 0)
		return false;
	if (check[i][j] == t)
		return dp[i][j];

	bool res = false;
	if (f1[i][j] % 2 == 0)
		if (f(i, j - 1) == false)
			res = true;
	if (f2[i][j] % 2 == 0)
		if (f(i - 1, j) == false)
			res = true;

	check[i][j] = t;
	return dp[i][j] = res;
}

void solve() {
	cin >> n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) {
			cin >> a[i][j];
			f1[i][j] = f1[i - 1][j] + a[i][j];
			f2[i][j] = f2[i][j - 1] + a[i][j];
		}

	bool res = f(n, n);
	if (res)
		printf("YES\n");
	else 
		printf("NO\n");
}

int main() {
	//freopen("test.inp", "r", stdin);
	scanf("%d", &q);

	for(t=1;t<=q;t++) 
		solve();

	return 0;
}