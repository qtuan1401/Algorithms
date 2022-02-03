#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i=1;i<=n;i++)
struct node {
    long long x, y, id;
};
inline bool cmp(node a, node b) {
	return (a.x < b.x || (a.x == b.x && a.y < b.y));
}
inline bool cw(node a, node b, node c) {
	return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) <= 0LL;
}
inline bool ccw(node a, node b, node c) {
	return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) >= 0LL;
}
inline bool check(node a, node b, node c) {
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) == 0;
}
node a[int(1e5)];
bool dd[int(1e5)];
vector<node> v;
int n, d, len, prelen;
int main() {
	//freopen("military.i39", "r", stdin);
	cin >> n;
	REP(i, n)
		cin >> a[i].x >> a[i].y, a[i].id = i;;
	while (true) {
		v.clear();
		REP(i, n)
			if (!dd[a[i].id]) {
				v.push_back(a[i]);
				//cout << a[i].x << " " << a[i].y << " "<<a[i].id << endl;
			}
		if (v.size() == 1) {
			cout << d;
			return 0;
		}
		sort(v.begin(), v.end(), &cmp);
		node p1 = v[0];
		node p2 = v.back();
		vector<node> up, down;
		up.push_back(p1);
		down.push_back(p1);
		for(int i = 1; i < v.size(); i++) {
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
		v.clear();
		prelen = len;
		for(int i = 0; i < up.size(); i++)
			dd[up[i].id] = true, len++, v.push_back(up[i]);
		for(int i = down.size() - 2; i > 0; i--)
			dd[down[i].id] = true, len++, v.push_back(down[i]);
		if (len == n) {
            if (len - prelen >= 3 )
                d++;
			cout << d;
			return 0;
		}
		else
			d++;
	}
	return 0;
}
