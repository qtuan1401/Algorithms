#include <bits/stdc++.h>

using namespace std;

const int md = 1e5 + 10;

bool cut[md];
int u[md], v[md], lab[md], a[md], n, m, q, ans[md], b[md]; 

int root(int i) {
	while (lab[i] > -1)
		i = lab[i];
	return i;
}

void Union(int i, int j) {
	int temp = lab[i] + lab[j];
	if (lab[i] < lab[j]) {
		lab[j] = i;
		lab[i] = temp;
	} else {
		lab[i] = j;
		lab[j] = temp;
	}
}

int main() {
	//freopen("test.inp", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin >> n >> m >> q;
	for(int i=1;i<=m;i++) 
		cin >> u[i] >> v[i];
	for(int i=1;i<=q;i++) {
		cin >> a[i];
		cut[a[i]] = 1;
	}
	memset(lab, -1, sizeof lab);
	for(int i=1;i<=m;i++) 
		if (!cut[i]) {
			int uu = root(u[i]);
			int vv = root(v[i]);
			if (uu != vv) 
				Union(uu, vv);
		}
	int res = 0;
	for(int i=1;i<=n;i++) { 
		//cout << root(i) <<" " << i << endl;
		if (root(i) == i) {
			ans[q]++;
	//		cout << root(i)  << " " << i << endl;
		}
	}
	for(int i=q-1;i>=1;i--) {
		int uu = root(u[a[i + 1]]);
		int vv = root(v[a[i + 1]]);
		if (uu != vv) {
			ans[i] = ans[i + 1] - 1;
			Union(uu, vv);
		} else 
			ans[i] = ans[i + 1];
	}
	for(int i=1;i<=q;i++)
		cout << ans[i] << '\n';
	return 0;
}