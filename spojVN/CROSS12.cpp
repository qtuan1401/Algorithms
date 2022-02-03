#include <bits/stdc++.h>

using namespace std;

const int md =  1e4 + 10;

int f[md], a[md], d[md];
int n, m;
string s;

int calc(string s, int r) {
	int i = 0, times = 1;
	while (i + r <= m) {
		times++;
		i += r;
		while (s[i] == '1')
			i--;
	}
	return times;
}

int main() {
	//freopen("test.inp", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	cin >> s;
	
	s = "0" + s + "0";
	for(int i=1;i<=n;i++) 
		d[i] = calc(s, a[i]);

	sort(d + 1, d + 1 + n);

	f[1] = d[1];
	f[2] = d[2];

	for(int i=3;i<=n;i++) 
		f[i] = min(f[i - 1] + d[1] + d[i], f[i - 2] + d[2] * 2 + d[i] + d[1]);

	cout << f[n];
	return 0;	
}