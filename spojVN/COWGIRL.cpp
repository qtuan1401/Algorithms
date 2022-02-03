#include <bits/stdc++.h>

using namespace std;

int f[35][64];
int s, m, n, q;

int getbit(int x, int  i) {
	return ((x >> i) & 1);
}

bool check(int j, int k, int n) {
	for(int i=1;i<n;i++) {
		int sum = getbit(j, i) + getbit(j, i - 1) + getbit(k, i - 1) + getbit(k, i);
		if (sum == 0 || sum == 4)
			return false;
	}
	return true;
}

void calc(int m, int n) {
	int res = 0;
	memset(f, 0, sizeof(f));
	int s = (1 << n) - 1;
	for(int i=0;i<=s;i++)
		f[1][i] = 1;
	for(int i=2;i<=m;i++) {
		for(int s1=0;s1<=s;s1++)
			for(int s2=0;s2<=s;s2++)
				if (check(s1, s2, n)) {
					f[i][s1] += f[i - 1][s2];
				}
	}
	for(int i=0;i<=s;i++)
		res += f[m][i];

	printf("%d\n", res);
}

int main() {
	//freopen("test.inp", "r", stdin);
	scanf("%d", &q);
	while (q--) {
		scanf("%d %d", &m, &n);
		calc(max(m, n), min(m, n));
	}
	return 0;
}