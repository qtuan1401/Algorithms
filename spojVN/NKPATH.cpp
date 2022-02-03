#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9;
const int md = 1e2 + 1;

int f[md][md], a[md][md];
int n, m;
long long res;

inline bool gcd(int x, int y) {
	while (y > 0) {
		x = x % y;
		int temp = x;
		x = y;
		y = temp;
	}
	if (x == 1) 
		return false;
	else 
		return true;
}

main() {
//	freopen("test.inp", "r", stdin);
	scanf("%d %d", &n, &m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d", &a[i][j]);

	for(int i=1;i<=n;i++)
		f[i][1] = 1;

	for(int i=1;i<=n;i++) {
		for(int j=1;j<m;j++) {
			for(int ii=i-1;ii>=1;ii--)
				for(int jj=j;jj>=1;jj--)
					if (gcd(a[i][j], a[ii][jj]))
						f[i][j] = (f[i][j] + f[ii][jj]) % mod;
				for(int jj=j-1;jj>=1;jj--)
					if (gcd(a[i][j], a[i][jj]))
						f[i][j] = (f[i][j] + f[i][jj]) % mod;
		}
 	}

 	for(int i=1;i<=n;i++) {
 		for(int ii=i;ii>=1;ii--)
 			for(int jj=m-1;jj>=1;jj--)
 				if (gcd(a[i][m], a[ii][jj]))
 					res = (res + f[ii][jj]) % mod;
 	}

 	printf("%lld", res);
}