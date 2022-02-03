#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 1; i <= (n); i++)
#define md int(1e6)
#define base int(1e9 + 7)
struct matrix {
	int a[55][55];
};
matrix a;
int n, k, b[md];
matrix operator * (matrix a, matrix b) {
	matrix c;
	REP(i, k)
		REP(j, k) {
			c.a[i][j]=0;
			REP(t, k)
				c.a[i][j] = (c.a[i][j] + (long long)(a.a[i][t]) * b.a[t][j]) % (base - 1);
		}
	return c;
}
inline int mu(int a, int n) {
	if (n == 0)
		return 1;
	else if (n == 1)
		return a;
	long long tmp = mu(a, n / 2);
	if (n & 1)
		return ((tmp * tmp) % base * a) % base;
	else 
		return (tmp * tmp) % base;
}
inline matrix calc(matrix a, int n) {
	if (n == 1)
		return a;
	matrix tmp = calc(a, n / 2);
	if (n & 1)
		return tmp * tmp * a;
	else 
		return tmp * tmp;
}
int main() {
	//freopen("test.inp", "r", stdin);
	scanf("%d %d", &n, &k);
	REP(i, k) 
		scanf("%d", &b[i]);
	REP(i, k - 1)
		a.a[i][i + 1] = 1;
	REP(i, k)
		a.a[k][i]=1;
	matrix r = calc(a, n - k);
	long long res = 1;
	REP(i, k)
		res = (res * mu(b[i], r.a[k][i])) % base;
	printf("%lld", res);
	return 0;
}