#include <bits/stdc++.h>

using namespace std;

typedef pair<long long, long long> ii;

const long long oo = 1e18;

vector< ii > v;
priority_queue< long long, vector< long long >, greater< long long > > heap;
int t;

long long calc(long long u) {
	if (u == 0)
		return 0;
	if (u == 1)
		return 1;
	if (u == 2)
		return 1;
	while (!(u & 1))
		u >>= 1;
	u >>= 1;
	long long x1, x2;
	x1 = x2 = 1;
	for(;u >= 2; u >>= 1) {
		if (!(u & 1))
			x1 += x2;
		else
			x2 += x1;
//		u >>= 1;
	}
	return x1 + x2;
}

long long bs(int l, int r, long long x) {
	long long res = 0;
	while (l <= r) {
			int mid = (l + r) >> 1;
			if (v[mid].first <= x) {
				res = v[mid].second;
				l = mid + 1;
			} else 
				r = mid - 1;
		}
	return res;
}

int main() {
	//freopen("test.inp", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	heap.push(1ll);
	v.push_back(ii(0, 0));
	while (!heap.empty()) {
		long long u = heap.top();
		heap.pop();
		ii cur = v[v.size() - 1];
		if (u != cur.first) {
			long long val = calc(u);
			if (val > cur.second) {
				v.push_back(ii(u, val));
				if (4 * u + 1 <= oo)
					heap.push(4 * u + 1);
				if (4 * u - 1 <= oo)
					heap.push(4 * u - 1);
				if (2 * u + 1 <= oo)
					heap.push(2 * u + 1);
				if (2 * u - 1 <= oo)
					heap.push(2 * u - 1);
			}
		}
	}
	int len = v.size() - 1;
	cin >> t;
	while (t--) {
		long long x;
		cin >> x;
		cout << bs(0, len, x) << '\n';
	}
	return 0;
}