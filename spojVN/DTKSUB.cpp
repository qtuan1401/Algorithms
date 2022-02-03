#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll base = 1e9 + 7;
const int md = 1e5 + 10;

ll Hash[md], Pow[md], b[md];
int n, k1;
char s[md];

ll getHash(int i, int j) {
	return (Hash[j] - Hash[i - 1] * Pow[j - i + 1] + base * base) % base;
} 

bool check(int k) {
	int r = 0;
	for(int i=1;i<=n - k + 1;i++)
		b[++r] = getHash(i, i + k - 1);
	//cout << k << endl;
	//for(int i=1;i<=r;i++)
	//	cout << b[i] << " ";
	//cout << endl;
	sort(b + 1, b + 1 + r);
	int d = 1;
	b[r + 1] = b[r] + 1;
	for(int i=1;i<=r;i++) 
		if (b[i] != b[i + 1]) {
			if (d >= k1)
				return true;
			d = 1;
		} else d++;
	return false;
}

int bs(int l, int r) {
	int pos = 0;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) {
			pos = mid;
			l = mid + 1;
		} else r = mid - 1;
	}

	return pos;
}

int main() {
//	freopen("test.inp", "r", stdin);
	scanf("%d %d", &n, &k1);
	scanf("%s", s);

	Pow[0] = 1;
	for(int i=1;i<=n;i++)
		Pow[i] = (Pow[i - 1] * 26) % base;
	for(int i=n;i>=1;i--)
		s[i] = s[i - 1];
	for(int i=1;i<=n;i++)
		Hash[i] = (Hash[i - 1] * 26 + s[i] - 'a') % base;	

	printf("%d", bs(1, n));
}