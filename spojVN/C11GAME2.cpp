#include <bits/stdc++.h>

using namespace std;

const int md = 205;
const int oo = 1e9;

int f[md][md][md];
int a[md], b[md];
int rb, ra, cnta, cntb, n;

int main() {
	//freopen("game.inp", "r", stdin);
	//freopen("game.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin >> n;
	for(int i=1;i<=n;i++) {
		int x;
		cin >> x;
		if (x == 0)
			cnta++;
		else 
			a[++ra] = x;
	}
	for(int i=1;i<=n;i++) {
		int x;
		cin >> x;
		if (x == 0)
			cntb++;
		else
			b[++rb] = x;
	}
	//cout << ra <<" " << rb<< endl;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=cnta;j++)
			for(int k=0;k<=cntb;k++)
				f[i][j][k] = -oo;
	//for(int i=1;i<=ra;i++)
	//	 cout << a[i] << " ";
	//cout << endl;
	//cout << cnta << " " << cntb << endl;
	f[0][0][0] = 0;
	for(int i=0;i<n;i++)
		for(int j=0;j<=cnta;j++)
			for(int k=0;k<=cntb;k++)
				if (f[i][j][k] > -oo) {
					//cout << f[i][j][k] + a[i - j + 1] * b[i - k + 1] << endl;
					if (j < cnta && k < cntb)
						f[i + 1][j + 1][k + 1] = max(f[i + 1][j + 1][k + 1], f[i][j][k]);
					if (j < cnta && i - k + 1 <= rb)
						f[i + 1][j + 1][k] = max(f[i + 1][j + 1][k], f[i][j][k]);
					if (i - j + 1 <= ra && k < cntb)
						f[i + 1][j][k + 1] = max(f[i + 1][j][k + 1], f[i][j][k]);
					if (i - j + 1 <= ra && i - k + 1 <= rb)
						f[i + 1][j][k] = max(f[i + 1][j][k], f[i][j][k] + a[i - j + 1] * b[i - k + 1]);
				}
	cout << f[n][cnta][cntb];
	return 0;
}