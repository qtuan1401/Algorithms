#include <bits/stdc++.h>

using namespace std;

const int MXN = 1e5 + 10;

long long res;
long long x[MXN], y[MXN], n, cntx, cnty, r, d;
double a[MXN];

int main() {
    ios_base::sync_with_stdio(0);
	cin >> n;
    if (n < 3) {
        cout << 0;
        return 0;
    }
	for(int i = 1; i <= n; i++)
		cin >> x[i] >> y[i];
	for(int i = 1; i <= n; i++) {
		cntx = 0;
		cnty = 0;
		r = 0;
		for(int j = 1; j <= n; j++) 
			if (i != j) {
				if (x[j] - x[i] == 0) {
					cntx++;
				}
				else if (y[j] - y[i] == 0) {
					cnty++;
				}
				else 
					a[++r] = (double)(x[j] - x[i]) / (y[j] - y[i]); 
			}
		if (cntx > 1) 
			res += cntx * (cntx - 1) / 2;
		if (cnty > 1)
			res += cnty * (cnty - 1) / 2;
		sort(a + 1, a + 1 + r);
		d = 1;
		for(int j = 2; j <= r; j++) {
			if (a[j] == a[j - 1]) 
				d++;
			else  {
				if (d > 1)
					res += d * (d - 1) / 2;
				d = 1;
			}
		}
		if (d > 1)
			res += d * (d - 1) / 2;
	}
	cout << n * (n - 1) * (n - 2) / 6 - res / 3;
}