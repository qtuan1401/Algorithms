#include <bits/stdc++.h>
 
using namespace std;
 
const int MAXN = 105;
const int MAXM = 65;
 
bool gauss[MAXM][MAXN];
int n, m;
 
long long GaussElimination() {
	int row = m - 1;
	long long ans = 0;
	for( ; row >= 0; row--) {
		ans <<= 1;
		int col = 0;
		for( ; col < n; col++)
			if (gauss[row][col]) {
				break;
			}
		if (col == n) {
			if (gauss[row][col] == 0)
				ans |= 1;
			continue;
		}
		ans |= 1;
		for(int i = row - 1; i >= 0; i--) {
			if (gauss[i][col] == 0) continue;
			for(int j = col; j <= n; j++)
				gauss[i][j] ^= gauss[row][j];
		}	
	}
	return ans;
}
 
int main() {
	ios_base::sync_with_stdio(0);
	cin >> n;
	for(int i = 0; i < n; i++) {
		long long x;
		cin >> x;
		int cnt = 0;
		while (x > 0) {
			gauss[cnt++][i] = (x & 1);
			x >>= 1;
		}
		m = max(m, cnt);
	}
	
	for(int i = 0; i < m; i++)
		gauss[i][n] = 1;
	
	cout << GaussElimination();
	return 0;
}