#include <bits/stdc++.h>

using namespace std;

const int md = 5e4 + 10;

int n, m, u, v, ru, rv, c;
map < int, int > mm;
int par[md], cnt[md];
string s;

int root(int i) {
	if (par[i] == i)
		return i;
	int temp = root(par[i]);
	cnt[i] ^= cnt[par[i]];
	return par[i] = temp;
}

int get(int i) {
	if (mm.find(i) == mm.end())
		mm[i] = ++c;
	return mm[i];
}

int main() {
	//freopen("test.in", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	cin >> m;
	for(int i = 0; i <= 2 * m; i++)
		par[i] = i;
	for(int i = 1; i <= m; i++) {
		cin >> u >> v >> s;
		//cout << u <<" " << v << endl;
		if (u > v)
			swap(u, v);
		int now = (s[0] == 'o');
		u = get(u - 1);
		v = get(v);
		//cout << u <<" " << v << endl;
		ru = root(u);
		rv = root(v);
		//cout << ru <<" " << rv << endl;
		//cout << cnt[u] <<"* " << cnt[v] << endl;
		if (ru == rv) {
			if (cnt[v] ^ cnt[u] != now) {
				cout << i - 1;
				return 0;
			}
		} else {
			par[rv] = ru;
			cnt[rv] = cnt[u] ^ cnt[v] ^ now;
		}
		//for(int i = 1; i <= n; i++)
	//		cout << cnt[i] <<" ";
	//	cout << endl;
	}
	cout << m;
	return 0;
}