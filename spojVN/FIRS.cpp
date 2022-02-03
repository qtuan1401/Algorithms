#include <bits/stdc++.h>
using namespace std;
#define md int(1e5 + 5)
#define REP(i, n) for(int i = 1; i <= (n); i++)
pair<int, int> a[md];
int n;
bool dd[md];
int main() {
	//freopen("test.inp", "r", stdin);
	scanf("%d", &n);
	REP(i, n)
		scanf("%d", &a[i].first), a[i].second = i;
	sort(a + 1, a + 1 + n);
	int res = 0;
	REP(i, n) 
		if (!dd[a[i].second]) {
			res++;
			int pos = a[i].second;
			dd[pos - 1] = true;
			dd[pos + 1] = true;
			dd[pos] = true;
		}
	printf("%d", res);
}