#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i= 1; i <= (n); i++)
#define FOR(i, a, b) for(int i= (a); i <= (b); i++) 
#define md int(1e4)
#define INF int(-1e9)
pair<double,int> c[md];
int x[md],y[md],n;
main()
{
	//freopen("test.inp","r",stdin);
	scanf("%d", &n);
	REP(i, 2 * n)
		scanf("%d %d", &x[i], &y[i]);
	REP(i, n) {
		FOR(j, n + 1, 2 * n) {
			double a = x[j] - x[i];
			double b = y[j] - y[i];
		//	cout << a << " " << b <<" "<< a/b << endl;
			if (!b)
				c[j].first =  INF;
			else 
				c[j].first = a / b;
			c[j].second = j;
		}
		sort(c + 2 + n, c + 2 * n + 1);
		FOR(j, n + 2, 2 * n) {
			if (c[j].first == c[j-1].first) {
				printf("%d %d %d", i, c[j-1].second, c[j].second);
				return 0;
			}
		}
	}
	FOR(i, n + 1, 2 * n) {
		REP(j, n) {
			double a = x[j] - x[i];
			double b = y[j] - y[i];
			if (!b)
				c[j].first = INF;
			else
				c[j].first = a / b;
			c[j].second = j;
		}
		sort(c + 1, c + 1 + n);
		FOR(j, 2, n)
			if (c[j].first == c[j-1].first) {
				printf("%d %d %d", c[j-1].second, c[j].second, i);
				return 0;
			}
	}
	printf("-1");
}