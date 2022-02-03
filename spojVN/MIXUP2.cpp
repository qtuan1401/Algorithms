#include <bits/stdc++.h>

using namespace std;

long long res;
long long f[20][100000];
int a[20],n,k,r;

int getbit(int x, int i) {
	return ((x >> i) & 1);
}

int offbit(int x, int i) {
	return (x & (~(1 << i)));
}

int main() {
//	freopen("test.inp", "r", stdin);
	scanf("%d %d", &n, &k);
	for(int i=1;i<=n;i++)
		scanf("%d", &a[i]);

	r = (1 << n) - 1;
	for(int i=0;i<n;i++)
		f[i][1 << i] = 1;

	for(int s=1;s<=r;s++) {
		for(int i=0;i<n;i++)
			if (getbit(s, i)) {
				int pre = offbit(s, i);
				for(int j=0;j<n;j++)
					if (getbit(pre, j))
						if (abs(a[i + 1] - a[j + 1]) > k)
							f[i][s] += f[j][pre];
			}
	}

	for(int i=0;i<n;i++)
		res += f[i][(1 << n) - 1];
	printf("%lld", res);
	return 0;
}