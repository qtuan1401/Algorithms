#include <bits/stdc++.h>

using namespace std;

typedef pair<long long, long long> ii;

const long long md = 1e5 + 10;
long long INF = 1e15;

struct node {
	long long pos, p, val;
} t[md * 8];

long long a[md];
long long n, q;
long long res;

void build(long long k, long long l, long long r) {
	t[k].p = 0;
	if (l == r) {
		t[k].val = a[l];
		t[k].pos = l;
		return;
	}
	long long mid = (l + r) >> 1;
	build(k * 2, l, mid);
	build(k * 2 + 1, mid + 1, r);

	if (t[k * 2].val > t[k * 2 + 1].val) {
		t[k].val = t[k * 2].val;
		t[k].pos = t[k * 2].pos;
	} else {
		t[k].val = t[k * 2 + 1].val;
		t[k].pos = t[k * 2 + 1].pos;
	}
}

void lazy(long long k) {
	long long v = t[k].p;
	t[k * 2].p += v;
	t[k * 2 + 1].p += v;
	t[k * 2].val += v;
	t[k * 2 + 1].val += v;
	t[k].p = 0;
}

void update(long long k, long long a, long long b, long long l, long long r, long long val) {
	if (r < a || l > b) 
		return ;
	if (a <= l && r <= b) {
		t[k].p += val;
		t[k].val += val;
		return;
	}
	lazy(k);
	long long mid = (l + r) >> 1;
	update(k * 2, a, b, l, mid, val);
	update(k * 2 + 1, a, b, mid + 1, r, val);
	if (t[k * 2].val > t[k * 2 + 1].val) {
		t[k].val = t[k * 2].val;
		t[k].pos = t[k * 2].pos;
	} else {
		t[k].val = t[k * 2 + 1].val;
		t[k].pos = t[k * 2 + 1].pos;
	}
}

ii get(long long k, long long a, long long b, long long l, long long r) {
	if (r < a || l > b)
		return ii(-INF, 0);
	if (a <= l && r <= b) 
		return ii(t[k].val, t[k].pos);
	lazy(k);
	long long mid = (l + r) >> 1;
	ii s1 = get(k * 2, a, b, l, mid);
	ii s2 = get(k * 2 + 1, a, b, mid + 1, r);
	if (s1.first < s2.first)
		return s2;
	else 
		return s1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin >> n;
	for(long long i=1;i<=n;i++)
		cin >> a[i];

	build(1, 1, n);
	//cout << get(1, 2, 4, 1, n)<< endl;

	cin >> q;
	char c;
	long long u, v;
	while (q--) {
		cin >> c >> u >> v;
		//cout <<  c << " " << u << " " << v << endl;
		if (c == 'U') {
			update(1, u, u, 1, n, v - a[u]);
			a[u] = v;
		} else {
			ii Max = get(1, u, v, 1, n);
			//cout << Max.first << " " << Max.second << endl;
			res = Max.first;
			update(1, Max.second, Max.second, 1, n, -INF - Max.first);
			res += get(1, u, v, 1, n).first;
			update(1, Max.second, Max.second, 1, n, Max.first - (-INF));
			cout << res << "\n";
		}
	}
	return 0;
}