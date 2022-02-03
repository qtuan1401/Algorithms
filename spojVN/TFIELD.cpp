#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<long long, long long> ii;
const int md = 1e4 + 10;
int m, k;
long long b[md][5];
ii a[md];

ll area(ll xa, ll ya, ll xb, ll yb) {
	return (xa * yb - xb * ya);
}

int c, n;
int cnt[md];
long long res = 0;

int main() {
	//freopen("test.in", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin >> m >> k;
	for(int i=1;i<=m;i++) {
		cin >> n;
		cin >> c;
		a[i].second = c;
		for(int j=1;j<=n;j++) {
			int x, y;
			cin >> x >> y;
			b[j][0] = x;
			b[j][1] = y;
		}
		b[n + 1][0] = b[1][0];
		b[n + 1][1] = b[1][1];
		long long ss = 0;
		for(int j=1;j<=n;j++) {
			ss += area(b[j][0], b[j][1], b[j + 1][0], b[j + 1][1]);
		}
		a[i].first = abs(ss);
	}
	sort(a + 1, a + 1 + m);
	reverse(a + 1,a + 1 + m);
	for(int i=1;i<=m;i++) {
		int Max = 0;
		for(int j=1;j<=m;j++)
			cnt[j] = 0;
		for(int j=i;j>=1;j--) {
			cnt[a[j].second]++;
			Max = max(cnt[a[j].second], Max);
			if ((i - j + 1) - Max <= k) 
				res = max(res, a[j].first - a[i + 1].first);
		}
	}
	if (res & 1)
		cout << res / 2 << ".5";
	else
		cout << res / 2 << ".0";
	return 0;
}