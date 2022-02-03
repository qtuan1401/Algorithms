#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i=1;i<=(n);i++)
#define FOR(i, a, b) for(int i=(a);i<=(b);i++)
#define md 20
int n, low[md];
long long res, gt[md], s, a[md], x;
bool kt[md];
int main() {
	//freopen("test.inp", "r", stdin);
	//scanf("%d", &n);
	while (scanf("%lld", &a[++n]) != EOF);
	n -= 2;
	s = a[n + 1];
	gt[0] = 1;
	REP(i, n)
		gt[i] = gt[i - 1] * i, low[i] = i - 1;
	REP(i, n) {
		int cnt = 0;
		FOR(j, i + 1, n)
			if (a[i] > a[j])
				cnt++; 
		res += cnt * gt[n - i];
	}
	printf("%lld\n", res + 1);
	long long tmp = 0;
	int l = 0;
	REP(i, n) {
		REP(j, n) 
			if (!kt[j]) {
				if (low[j] * gt[n - i] < s) {
					l = j;		
					//break;
				}
				else break;
			}
		a[i] = l;
		s -= low[l] * gt[n - i];
		FOR(j, l + 1, n)
			low[j]--;
		kt[l] = true;
	}
	REP(i, n)
		printf("%lld ", a[i]);
}