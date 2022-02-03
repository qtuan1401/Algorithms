#include <bits/stdc++.h>
 
using namespace std;
 
const int md = 2e3 + 10;
 
int dp[md][md], pos[md][260];
string a, b;
 
int main() {
	//freopen("test.inp", "r", stdin);
	ios_base::sync_with_stdio(0);
	getline(cin, a);
	getline(cin, b);
	int m = a.size();
	int n = b.size();
	if (m > n) {
		swap(a, b);
		swap(m, n);
	}
	a = ' ' + a;
	b = ' ' + b;
	//cout << m <<" " << n << endl;
	for(int c=1;c<=255;c++) 
		for(int i=m-1;i>=0;i--) {
			//cout << int(a[i + 1]) << " " << c << endl;
			pos[i][c] = (a[i + 1] == c) ? i + 1 : pos[i + 1][c];
		}
	memset(dp, -1, sizeof dp);
	dp[0][0] = 0;
	for(int i=0;i<n;i++)
		for(int j=0;j<=i;j++) 
			if (dp[i][j] >= 0) {
				dp[i + 1][j] = (dp[i + 1][j] == -1) ? dp[i][j] : min(dp[i][j], dp[i + 1][j]);
				int newPos = pos[dp[i][j]][b[i + 1]];
				//cout << newPos << endl;
				if (newPos > 0)
					dp[i + 1][j + 1] = (dp[i + 1][j + 1] == -1) ? newPos : min(newPos, dp[i + 1][j + 1]);
			}
	int len = min(n, m);
	int ans = 0;
	for(int j=len;j>=1;j--) {
		for(int i=j;i<=n;i++) 
			if (dp[i][j] >= 0)
				ans = j;
		if (ans != 0)
			break;
	}
	cout << ans;
	return 0;
}