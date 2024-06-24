// codeforces 86d

#include <bits/stdc++.h>
 
using namespace std;
 
const int md = 1e6 + 10;
 
struct node {
	int l, r, id;
	bool input(int i) {
		cin >> l >> r;
		id = i;
	}	
};
 
 
int a[md], cnt[md];
long long ans[md];
node q[md];
int n, m, l = 1, r, block;
long long res;
 
bool cmp(node a, node b) {
	if ((a.l  - 1) / block != (b.l - 1) / block)
		return a.l < b.l;
	else return a.r < b.r;
}
 
inline long long sqr(int x) {
	return 1ll * x * x;
}
 
int main() {
	//freopen("test.in", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	for(int i=1;i<=m;i++)
		q[i].input(i);
	//square root decomposition
	block = sqrt(n);
	sort(q + 1, q + 1 + m, cmp);
	for(int i=1;i<=m;i++) {
		while (r < q[i].r) {
			r++;
			res -= 1ll * a[r] * sqr(cnt[a[r]]);
			cnt[a[r]]++;
			res += 1ll * a[r] * sqr(cnt[a[r]]);
		}
		while (r > q[i].r) {
			res -= 1ll * a[r] * sqr(cnt[a[r]]);
			cnt[a[r]]--;
			res += 1ll * a[r] * sqr(cnt[a[r]]);
			r--;
		}
		while (l < q[i].l) {
			res -= 1ll * a[l] * sqr(cnt[a[l]]);
			cnt[a[l]]--;
			res += 1ll * a[l] * sqr(cnt[a[l]]);
			l++;
		}
		while (l > q[i].l) {
			l--;
			res -= 1ll * a[l] * sqr(cnt[a[l]]);
			cnt[a[l]]++;
			res += 1ll * a[l] * sqr(cnt[a[l]]);
		}
		ans[q[i].id] = res;
	}
	for(int i=1;i<=m;i++)
		cout << ans[i] << '\n';
	return 0;
}