#include <bits/stdc++.h>

using namespace std;

const int md = 1e2 + 10;

int a[int(1e4 + 10)];
long long c[md][md];
int n, m;
long long res;

int main() {
	//freopen("test.inp", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	for(int i=1;i<=m;i++)
		cin >> a[i];

	for(int i=1;i<=n;i++) 
		for(int j=1;j<=n;j++)
			cin >> c[i][j];

	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				c[i][j] = min(c[i][k] + c[k][j], c[i][j]);

	for(int i=1;i<m;i++)
		res += c[a[i]][a[i + 1]];

	if (a[m] != n)
		res += c[a[m]][n];

	cout << res;
	return 0;
}