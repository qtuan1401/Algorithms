#include <bits/stdc++.h>

using namespace std;

const int md = 1e4 + 5;

int a[md], b[md], trace[md], f[md], Max, pos;
int n, m, t;

int main() {
	//freopen("test.inp", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for(int i=1;i<=n;i++)
			cin >> a[i];
		for(int i=1;i<=m;i++)
			cin >> b[i], f[i] = 0;
		for(int i=1;i<=n;i++) {
			Max = 0;
			pos = 0;
			for(int j=1;j<=m;j++) {
				if (a[i] >= b[j] * 2 && Max < f[j]) {
					Max = f[j];
					//pos = j;
				} else if (a[i] == b[j]) {
					f[j] = Max + 1;
					//trace[j] = pos;
				}
			}
		}
		Max = -1;
		for(int i=1;i<=m;i++)
			if (f[i] > Max) {
				Max = f[i];
				//pos = i;
			}
		cout << Max << "\n";
	}
	return 0;
}