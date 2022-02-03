#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int md = 1e6 + 10;

ll t[md], a[md];
ll q, n, seed, add, k, mul;

void update(ll x, ll val) {
	while (x <= 65540) {
		t[x] += val;
		x += (x & (- x));
	}
}

ll sum(ll x) {
	ll res = 0;
	while (x > 0) {
		res += t[x];
		x -= (x & (- x));
	}
	return res;
}

ll bs(ll k) {
	ll l = 1;
	ll r = 65540;
	ll pos = 0;
	while (l <= r) {
		ll mid = (l + r) >> 1;
		if (sum(mid) >= k) {
			pos = mid;
			r = mid - 1;
		} else l = mid + 1;
	}
	return pos;
}

int main() {
	//freopen("test.inp", "r", stdin);
	ios_base::sync_with_stdio(0);

	cin >> q;

	for(int test=1;test<=q;test++) {
		cin >> seed >> mul >> add >> n >> k;

		//memset(a, 0, sizeof(a));
		memset(t, 0, sizeof(t));
		
		ll res = 0;
		a[1] = seed;
		update(a[1] + 1, 1LL);
		if (k == 1)
			res += bs(1) - 1;
		for(int i=2;i<=n;i++) {
			a[i] = (a[i - 1] * mul + add) % 65536;
			update(a[i] + 1, 1);
			if (i >= k) {
				if (i - k != 0)
					update(a[i - k] + 1, -1);
				res += bs((k + 1) / 2) - 1;
			}
		}

		cout <<"Case #"<<test<<": "<< res << "\n";
	}
	return 0;
}