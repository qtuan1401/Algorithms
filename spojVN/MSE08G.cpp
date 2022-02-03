#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll inf = 1e12;
const int md = 1e4 + 10;
int r, cnt, q;
ll d[md], ans[md * 100];

void init(ll v, ll n) {
	if (n > 12)
		return ; 
	d[++r] = v * 10 + 4;
	d[++r] = v * 10 + 7;
	init(v * 10 + 4, n + 1);
	init(v * 10 + 7, n + 1);
}

void prepare(ll v, ll l) {
	for(int i=l;i<=r;i++) {
		ll temp = v * d[i];
		if (temp < inf && temp > 0) {
			ans[cnt++] = temp;
			prepare(temp, i);
		} else break;
	}
}

int bs(ll x) {
	int l = 0, r = cnt + 1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (ans[mid] <= x)
			l = mid + 1;
		else 
			r = mid - 1;
	}
	return l;
}

int main() {
	//freopen("test.inp", "r", stdin);
	ios_base::sync_with_stdio(0);
	init(0, 1);
	sort(d + 1, d + r + 1);
	prepare(1, 1);
	sort(ans, ans + cnt);
	cnt = unique(ans, ans + cnt) - ans;
	ans[cnt] = inf + 1;
	cin >> q;
	while (q--) {
		ll a, b;
		cin >> a >> b;
		cout << bs(b) - bs(a - 1) << "\n";
	}
	return 0;
}