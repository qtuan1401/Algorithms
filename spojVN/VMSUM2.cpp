#include <bits/stdc++.h>

using namespace std;
 
typedef long double ld;

const int md = 1e6 + 10;
const int oo = 1e6;

int n;
ld f[md], g[md], h[md], r[md];
 
void prepare() {
	for(int i = 1; i <= oo; i++) 
		g[i] = g[i - 1] + 1.0 / i;
	f[3] = 0.5;
	for(int i = 4; i <= oo; i++) {
		f[i] = g[i - 1];
		if (i % 2 == 0) 
			f[i] -= 2.0 / i;
		f[i] /= i;
	}
	/*for(int i = 1; i <= 10; i++)
	 	cout << f[i] << " ";
	cout << endl;*/
	for(int i = 3; i <= oo; i++)	
		for(int j = 2; i * j <= oo; j++) 
			f[i * j] -= f[i] / j / j;
	/*for(int i = 1; i <= 10; i++)
		cout << f[i] <<" ";
	cout << endl;*/
	for(int i = 1; i <= oo; i++) 
		h[i] = g[i - 1] / i;
	h[2] = 0.5;
	for(int i = 2; i <= oo; i++)
		for(int j = 2; i * j <= oo; j++) 
			h[i * j] -= h[i] / j / j;
	for(int i = 2; i <= oo; i++) 
		r[i] = r[i - 1] - f[i - 1] + h[i];
	for(int i = 2; i <= oo; i++) 
		r[i] += r[i - 1];
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
	//freopen("test.in", "r", stdin);
	prepare();
	cout << fixed << setprecision(9);
	while (cin >> n) {
		cout << r[n] << '\n';
	}
	return 0;
}