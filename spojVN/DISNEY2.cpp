#include <bits/stdc++.h>
using namespace std;
 
#define REP(i, n) for(int i=1;i<=(n);i++)

const int md = 2e2 + 10;

int res = int(1e6);
int f[md][md], n, a[md][md];
 
int main() {
	//freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	
	scanf("%d", &n);

	REP(i, n)
		REP(j, n)
			scanf("%d", &a[i][j]);
 
	memset(f, res, sizeof(f));	
	f[1][1] = 0;
 
	REP(i, n - 1)
		REP(j, n - 1) {
			int k = max(i, j) + 1;
			f[i][k] = min(f[i][k], f[i][j] + a[j][k]);
			f[k][j] = min(f[k][j], f[i][j] + a[i][k]);
		//	f[k][k] = min(f[k][k], f[i][j] + a[j][k] + a[i][k]);
		}
	REP(i, n) {
		res = min(res, f[i][n] + a[1][i] + a[1][n]);
		res = min(res, f[n][i] + a[i][1] + a[n][1]);
	}
 
	printf("%d", res);
 
	return 0;
}  