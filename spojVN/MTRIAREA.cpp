#include <bits/stdc++.h>

using namespace std;

struct node {
	int x, y;
	node(int a = 0, int b = 0) {
		x = a;
		y = b;
	}
};

vector< node > v;
int n;

inline bool cmp(node a, node b) {
	return (a.x < b.x || (a.x == b.x && a.y < b.y));
}

inline int cw(node a, node b, node c) {
	return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) < 0;
}

inline int ccw(node a, node b, node c) {
	return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) > 0;
}

int calc(node a, node b, node c) {
	return abs(a.x * b.y - a.y * b.x + b.x * c.y - c.x * b.y + c.x * a.y - a.x * c.y);
}

inline int Next(int x) {
	if (x < n - 1)
		return x + 1;
	return 0;
}

int main() {
	// freopen("test.inp", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while (cin >> n) {
		if (n == -1)
			return 0;
		v.clear();
		for(int i=1;i<=n;i++) {
			int x, y;
			cin >> x >> y;
			v.push_back(node(x, y));
		}
		sort(v.begin(), v.end(), &cmp);
		node p1 = v[0];
		node p2 = v.back();
		vector< node > up, down;
		up.push_back(p1);
		down.push_back(p1);
		for(int i=1;i<v.size();i++) {
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
		for(int i=0;i<up.size();i++)
			v.push_back(up[i]);
		for(int i=down.size()-2;i>0;i--)
			v.push_back(down[i]);
		n = v.size();
		int a = 0, b = 1, c = 2;
		int res = calc(v[0], v[1], v[2]);
		while (true) {
			while (true) {
				while (calc(v[a], v[b], v[c]) <= calc(v[a], v[b], v[Next(c)]))
					c = Next(c);
				if (calc(v[a], v[b], v[c]) <= calc(v[a], v[Next(b)], v[c])) {
					b = Next(b);
					continue;
				}
				else
					break;
			} 
			res = max(res, calc(v[a], v[b], v[c]));
			a = Next(a);
			if (a == b)
				b = Next(b);
			if (b == c)
				c = Next(c);
			if (a == 0)
				break;
		}
		if (res & 1)
			cout << res / 2 << ".50\n";
		else 
			cout << res / 2 << ".00\n"; 
	}
	return 0;
}