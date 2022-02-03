#include <bits/stdc++.h>
using namespace std;

const int md = 1e6 + 10;
 
int d[md];
long long ans[md];
char s[md];
int n, cnt;

int main() {
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	
	scanf("%s", s);
	
	n = strlen(s);
	for(int i=0;i<n;i++)
		if (s[i] == '7')
			d[i]++;
	for(int i=0;i<n;i++)
		if (d[i])
			d[i] += d[i - 1];

	for(int i=n - 2;i >= 0; i--)
		if (d[i] != 0 && d[i + 1] > d[i])
			d[i] = d[i + 1];

	cnt = 0; 
	for(int i=0;i<n;i++)
		if (s[i] == '7') {
			cnt++;
			ans[cnt] += d[i] - cnt + 1; 
		} else cnt = 0;
	for(int i=1;;i++) {
		if (!ans[i])
			break;
		printf("%lld %lld\n", i, ans[i]);
	}
	
	return 0;
}