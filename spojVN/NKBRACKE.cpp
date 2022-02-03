#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 1; i <= (n); i++)
#define md int(1e5 + 5)
#define INF int(1e9)
struct node {
	int p, val;
} t[4 * md];
int t1[4 * md];
int m, n, a[md];
char s[md];
inline void up(int m, int val) {
	while (m <= md) {
		t1[m] += val;
		m += (m & (-m));
	}
}
inline int sum(int m) {
	int res = 0;
	while (m > 0) {
		res += t1[m];
		m -= (m & (-m));
	}
	return res;
}
inline void build(int k, int l, int r) {
	t[k].p = 0;
	if (l == r) {
		t[k].val = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(k * 2, l, mid);
	build(k * 2 + 1, mid + 1, r);
	t[k].val = min(t[k * 2].val, t[k * 2 + 1].val);
}
inline void lazy(int k) {
	int v = t[k].p;
	t[k * 2].p += v;
	t[k * 2 + 1].p += v;
	t[k * 2].val += v;
	t[k * 2 + 1].val += v;
	t[k].p = 0;
}
inline void update(int k, int a, int b, int l, int r, int val) {
	if (r < a || l > b) 
		return ;
	if (a <= l && r <= b) {
		t[k].p += val;
		t[k].val += val;
		return;
	}
	lazy(k);
	int mid = (l + r) >> 1;
	update(k * 2, a, b, l, mid, val);
	update(k * 2 + 1, a, b, mid + 1, r, val);
	t[k].val = min(t[k * 2].val, t[k * 2 + 1].val);
}
inline int get(int k, int a, int b, int l, int r) {
	if (r < a || l > b)
		return INF;
	if (a <= l && r <= b) 
		return t[k].val;
	lazy(k);
	int mid = (l + r) >> 1;
	return min(get(k * 2, a, b, l, mid), get(k * 2 + 1, a, b, mid + 1, r));
}
int main() {
//	freopen("test.inp", "r", stdin);
	scanf("%d %d", &n, &m);
	scanf("%s", s);
	REP(i, n) {
		if (s[i - 1] == '(')
			a[i] = a[i - 1] + 1, up(i, 1);
		else 
			a[i] = a[i - 1] - 1, up(i, -1);
	}
	build(1, 1, n);	
	char c;
	int u, v, type, l;
	while (m-- ) {
		scanf("%d", &type);
		if (type) {
			scanf("%d %d", &u, &v);
			int Min = get(1, u, v, 1, n);
			int l = sum(u - 1);
			int r = sum(v);
		//	cout << l << " "<<r << " ";
			if (Min >= l && l == r)
				printf("1");
			else
				printf("0");
		}
		else {
			scanf("%d %c", &l, &c);
			if (c == '(' && s[l - 1] == ')')
				update(1, l, n, 1, n, 2), up(l, 2), s[l - 1] = '(';
			else if(c == ')' && s[l - 1] == '(')
				update(1, l, n, 1, n, -2), up(l, -2), s[l - 1] = ')';
		}
	}
	return 0;
}  