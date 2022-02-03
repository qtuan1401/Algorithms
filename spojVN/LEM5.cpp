#include <bits/stdc++.h>
using namespace std;
#define x first 
#define y second 
const int md = 1e5 + 5;
pair<int, int> a[md];
int n;
int f[md], res;
int main() {
	//freopen("test.inp", "r", stdin);
	scanf("%d", &n);
	for(int i=1;i<=n;i++) {
		scanf("%d", &a[i].x);
		a[i].y = i;
	}
	sort(a + 1, a + 1 + n);
	for(int d=1;d<=100;d++) {
		for(int k=1;k<=n;k++)
			f[k] = 1;
		for(int i=1, j = 1; i<=n;) { 
			while (j <= n && a[j].x - a[i].x < d)
				j++;
			int pi = i + 1;
			while (pi <= n && a[pi].x == a[i].x)
				pi++;
			int pj = j + 1;
			while (pj <= n && a[pj].x == a[j].x)
				pj++;
			if (a[j].x - a[i].x == d) {
				for(;j<pj;j++) {
					while (i < pi && a[i].y < a[j].y) 
						f[j] = max(f[j], f[i++] + 1);
				}
			}
			i = pi;
		}
		for(int i=1;i<=n;i++)
			res = max(res, f[i]);
	}
	cout << res << endl;
	return 0;
}