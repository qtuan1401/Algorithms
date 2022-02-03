#include <bits/stdc++.h>

using namespace std;

const int md = 110;
const int oo = 1e9 + 10;

int f[md][md], val3[md], val2[md][md], val1[md], a[md];
int n, e, pos;
bool ok = false;

int main() {
	//freopen("test.in", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin >> n >> e;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 2; i <= n; i++)
		for(int j = 1; j < i; j++) 
			val1[i] += abs(a[i] - a[j]) * 2; 	
	for(int i = n; i >= 1; i--)
		for(int j = n; j > i; j--)
			val3[i] += abs(a[i] - a[j]) * 2;
//	for(int i = 1; i <= n; i++)
//		cout << val3[i] << " ";	
	for(int i = 1; i < n; i++)
		for(int j = 1; j <= n; j++)
			for(int k = i + 1; k <= j - 1; k++) {
				val2[i][j] += abs(2 * a[k] - a[i] - a[j]);
//				cout << val2[i][j] << endl;
			}
	for(int i = 2; i <= n; i++)
		for(int j = 2; j <= n; j++)
			f[i][j] = oo;
	for(int i = 1; i <= n; i++)
		f[1][i] = val1[i];
	for(int i = 2; i <= n; i++)
		for(int j = i; j <= n; j++)
			for(int k = 1; k < j; k++) 
				f[i][j] = min(f[i][j], f[i - 1][k] + val2[k][j]);
//	for(int i = 1; i <= n; i++) {
//		for(int j = 1; j <= n; j++)
//			cout << f[i][j] <<" ";
//		cout << endl;
//	}
	for(int i = 1; i <= n; i++) {
		for(int j = i; j <= n; j++)
			if (f[i][j] + val3[j] <= e) {
				pos = i;
				ok = true;
				break;
			}
		if (ok)
			break;
	}
	cout << pos << " ";
	for(int i = pos; i <= n; i++)
		if (f[pos][i] + val3[i] < e)
			e = f[pos][i] + val3[i];
	cout << e;
} 