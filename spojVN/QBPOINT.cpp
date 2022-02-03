#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(long long i=1;i<=(n);i++)
#define FOR(i, a, b) for(long long i=(a);i<=(b);i++)
#define md long long(1e5)
long long res;
long long x[md], y[md], n, cntx, cnty, r, d;
double a[md];
long long main() {
//	freopen("test.inp", "r", stdin);
	cin >> n;
	REP(i, n)
		cin >> x[i] >> y[i];
	REP(i, n) {
		cntx = 0;
		cnty = 0;
		r = 0;
		REP(j, n) 
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
		FOR(j, 2, r) {
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
	cout << res / 3;
}