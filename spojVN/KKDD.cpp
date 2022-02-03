#include <bits/stdc++.h>

using namespace std;

#define REP(i, n) for(int i=1;i<=(n);i++)
const int md = 1e4 + 10;
typedef long long ll;

int a[md];
ll f[md];
int n, k;

class solve {
public:
	priority_queue< int > low;
	priority_queue< int, vector< int >, greater< int > > high;
	long long l, r, lsum, rsum, median;
	solve(int md) {
		median  = -1;
		lsum = rsum = 0;
	}

	void add(int x) {
		if (median == -1) {
			median = x;
		} else {
			int mid = (low.size() + high.size() + 1) >> 1;
		//	cout << low.size() << " " << high.size() << " " << mid << endl;
			if (x < median) {
				if (low.size() < mid) {
					low.push(x);
					lsum += x;
				} else {
					high.push(median);
					rsum += median;
					int val;
					if (low.size())
						val = low.top();
					if (low.empty() || x >= val) {
						median = x;
					} else {
						low.pop();
						lsum = lsum - val + x;
						median = val;
						low.push(x);
					}
				}
			} else {
				if (low.size() >= mid) {
					high.push(x);
					rsum += x;
				} else {
					low.push(median);
					lsum += median;
					int val;
					if (high.size())
						val = high.top();
					if (high.empty() || x <= val) {
						median = x;
					} else {
						high.pop();
						rsum = rsum - val + x;
						median = val;
						high.push(x);
					}
				}
			}
		//	cout << low.size() << " " << high.size() << endl;
		}
		/*if (low.size())
			cout << low.top() << " ";
		if (high.size())
			cout << high.top() << endl;*/
	}

	ll get() {
		ll l = 1LL * median * low.size() - lsum;
		ll r = rsum - 1LL * median * high.size();
		return l + r;
	}
};

int main() {
	//freopen("test.inp", "r", stdin);
	//freopen("test1.out", "w", stdout);
	scanf("%d %d", &n, &k);
	REP(i, n)
		scanf("%d", &a[i]);

	memset(f, -1, sizeof(f));
	f[0] = 0;

	REP(i, n) {
		int l = max(i - k - k + 1, 1);
		//cout << i << " " << l << endl;
		solve z(md);
		for(int j=i;j>=l;j--) {
			// << j << endl;
			z.add(a[j]);
			if (i - j + 1 >= k && ~f[j - 1]) {
				ll val = f[j - 1] + z.get();
				if (f[i] == - 1 || f[i] > val)
					f[i] = val;
			}
		}
	}
	printf("%lld", f[n]);
	return 0;
}