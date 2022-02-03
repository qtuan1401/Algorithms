#include <bits/stdc++.h>
using namespace std;
#define md int(3e4 + 5)
struct point {
	long long x, y;
	point(long long a = 0, long long b = 0) {
		x = a;
		y = b;
	}
} ha[md], hb[md];	

long long ra, rb, q, n;
vector< point > a, b;
long long res;
bool cmp(point a, point b) {
	return (a.x < b.x || (a.x == b.x && a.y < b.y));
}
inline bool ccw(point a, point b, point c) {
	return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) > 0;
}
inline bool cw(point a, point b, point c) {
	return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) < 0;
}
void convex_hull(long long& r, point h[], vector< point > v) {
	sort(v.begin(), v.end(), &cmp); 
	point p1 = v[0];
	point p2 = v.back();
	vector< point > down, up;
	up.push_back(p1);
	down.push_back(p1);
	for(long long i = 1; i < v.size(); i++) {
		if (i == v.size() - 1 || cw(p1, v[i], p2)) {
			while (up.size() >= 2 && !cw(up[up.size() - 2], up[up.size() - 1], v[i]))
				up.pop_back();
			up.push_back(v[i]);
		}
		if (i == v.size() - 1 || ccw(p1, v[i], p2)) {
			while (down.size() >= 2 && !ccw(down[down.size() - 2], down[down.size() - 1], v[i]))
				down.pop_back();
			down.push_back(v[i]);
		}
	}
	r = 0;
	for(long long i = 0; i < up.size(); i++) 
		h[++r] = up[i];
	for(long long i = down.size() - 2; i > 0; i--)
		h[++r] = down[i];
}
inline long long dis(const point& a,const point& b) {
	return (1LL * (a.x - b.x) * (a.x - b.x) + 1LL * (a.y - b.y) * (a.y - b.y));
}
inline long long calc(long long res) {
	long long ans = (long long)(sqrt(res));
	if (ans * ans > res)
		ans--;
	return ans;
}
inline long long next(long long x, long long n) {
	if (x < n)
		x++;
	return x;
}
inline long long pre(long long x, long long n) {
	if (x > 1)
		x--;
	return x;
}
int main() {
//	freopen("test.inp", "r", stdin);
	scanf("%lLL", &q);
	while (q--) {
		res = 0;
		scanf("%lLL", &n);
		a.clear();
		b.clear();
		for(long long i = 1; i <= n; i++) {
			long long x, y, type;
			scanf("%lLL %lLL %lLL", &x, &y, &type);
			if (!type)
				a.push_back(point(x,y));
			else 
				b.push_back(point(x,y));
		}
		convex_hull(ra, ha, a);
 		convex_hull(rb, hb, b);

		for(long long i=1;i<=ra;i++)
			for(long long j=1;j<=rb;j++)
					res = max(res, dis(ha[i], hb[j]));
		long long ans = sqrt(res);
		assert(ans * ans <= res);
		while ((ans + 1) * (ans + 1) <= res)
			ans++;
		printf("%lLL\n", ans);
	}
	return 0;
}