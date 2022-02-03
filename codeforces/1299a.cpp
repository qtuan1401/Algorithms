#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;

int l[MAXN], r[MAXN], a[MAXN];
int n;

int main() {
	ios_base::sync_with_stdio(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	l[0] = ~a[0];
	for(int i = 1; i < n; i++)
		l[i] = l[i - 1] & (~a[i]);
	r[n - 1] = ~a[n - 1];
	for(int i = n - 2; i >= 0; i--)
		r[i] = r[i + 1] & (~a[i]);
	int mx = 0, pos = 0;
	for(int i = 0; i < n; i++) {
		int cur = 0;
		if (i > 0 && i < n - 1)
			cur = l[i - 1] & r[i + 1];
		else if (i > 0)
			cur = l[i - 1];
		else cur = r[i + 1];
		cur &= a[i];
		if (mx < cur) {
			mx = cur;
			pos = i;
		}
	}
	cout << a[pos] << " ";
	for(int i = 0; i < n; i++)
		if (i != pos)
			cout << a[i] << " ";
	return 0;
}