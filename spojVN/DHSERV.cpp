#include <bits/stdc++.h>

using namespace std;

const int md = 510;

int d[md][md];
int n, m, k;

int main() {
//	freopen("test.inp", "r", stdin);
	scanf("%d %d %d", &n, &m, &k);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if (i != j)
				d[i][j] = 1e9;
	for(int i=1;i<=m;i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);	
		d[u][v] = w;
	}

	while (k--) {
		int type;
		scanf("%d", &type);
		if (type == 1) {
			int x;
			scanf("%d", &x);
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					d[i][j] = min(d[i][j], d[i][x] + d[x][j]); 
		} else {
			int u, v;
			scanf("%d %d", &u, &v);
			if (d[u][v] == 1e9) printf("-1\n");
			else printf("%d\n", d[u][v]);
		}
	}
	return 0;
}