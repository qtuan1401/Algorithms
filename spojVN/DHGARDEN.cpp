#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i=1;i<=n;i++)
#define REV(i, n) for(int i=n;i>=1;i--)
#define md 15
int getbit(long long x, long long i) {
	return ((x >> i) & 1);
}
struct node {
	long long x, y;
};
bool cmp(node a, node b) {
	return (a.x < b.x || (a.x == b.x && a.y < b.y));
}
const long double pi = 3.14159265358979323846264338327950288;
const long double eps = 1e-20;
inline bool eq(const long double & a, const long double & b) {
  return fabs(a - b) <= eps * fabs(a);
}
long long q, d, n, R, ans, Max;
node a[md];
vector< node > v;
bool dd[md];
inline long double dis(node x, node y) {
	return sqrt((x.x - y.x) * (x.x - y.x) + (x.y - y.y) * (x.y - y.y));
}
inline bool cw(node a, node b, node c) {
	return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) <= 0LL;
}
inline bool ccw(node a, node b, node c) {
	return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) >= 0LL;
}
int main() {
	//freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	scanf("%lld", &q);
	while (q--) {
		scanf("%lld %lld %lld", &d, &n, &R);
		ans = 0;
		REP(i, n)
			scanf("%lld %lld", &a[i].x, &a[i].y);
		REP(state, 1 << n) {
			v.clear();
			//cout << state << endl;
			//for(int i=0;i<n;i++)
			//	cout << getbit(state,i);
			//cout << endl;
			//if (state == 1 << n) {
				for(int i=0;i<n;i++) 
					if (getbit(state, i)) { 
						v.push_back(a[i + 1]);
					//cout << getbit(state, i) << " " << i << endl;
				}
			Max = v.size();
			//}
			sort(v.begin(), v.end(), &cmp);
			node p1 = v[0];
			node p2 = v.back();
			vector<node> up, down;
			up.push_back(p1);
			down.push_back(p1);
			for(int i=1; i<v.size(); ++i) { 
			    if (i==v.size()-1 || cw (p1, v[i], p2)) {
			      while (up.size()>=2 && !cw (up[up.size()-2], up[up.size()-1], v[i]))
			        up.pop_back();
			      up.push_back (v[i]);
			    }
			    if (i==v.size()-1 || ccw (p1, v[i], p2)) {
			      while (down.size()>=2 && !ccw (down[down.size()-2], down[down.size()-1], v[i]))
			        down.pop_back();
			      down.push_back (v[i]);
			    }
  			}	
			v.clear();
			for(int i=0; i<up.size(); ++i)
				v.push_back (up[i]);
			for(int i=down.size()-2; i>0; --i)
			    v.push_back(down[i]);
			v.push_back(v[0]);
			/*if (state == (1 << n) - 1) {
				for(int i=0;i<v.size();i++)
					cout << v[i].x << " " <<v[i].y <<endl;
			}*/
			long double res = pi * 2 * R;
			for(int i=0; i < v.size() - 1; i++)
				res += dis(v[i], v[i + 1]);
			long long len = v.size() - 1;
		//	if (state == (1 << n) - 1)
		//		cout << res << " "<< len<< endl;
			if (res < d || eq(res, d))
				ans = max(ans, Max);
		}
		printf("%lld\n", ans);
	}
}