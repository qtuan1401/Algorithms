#include <bits/stdc++.h>

using namespace std;

string a;
int n;
int p[50004*2+1];
char b[50004*2+1];
int r = 0;

int main() {
	//freopen("test.inp", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin >> n >> a;
	b[++r] = '#';
	for(int i=0;i<n;i++) {
		b[++r] = a[i];
		b[++r] = '#';
	}
	b[++r] = 0;
	b[0] = '^';
	n = strlen(b + 1);
	int res = 0, c = 1, r = 1;
	for(int i=2;i<n;i++) {
		int mirror = 2 * c - i;
		if (r > i)
			p[i] = min(r - i, p[mirror]);
		else p[i] = 0;
		while (b[i - 1 - p[i]] == b[i + 1 + p[i]])
			p[i]++;
		res = max(res, p[i]);
		if (i + p[i] > r) {
			c = i;
			r = i + p[i];
		}
	}

	cout << res;
	return 0;
}