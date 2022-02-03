#include <bits/stdc++.h>

using namespace std;

const int md = 3e5 + 10;

pair<int, int> x[md];

long long len[md], s[md][5];
int n, a, b;

int bs1(int l, int r, int i) {
	int pos = 0;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (s[i][1] - s[mid - 1][1] >= a) {
			if (s[i][1] - s[mid - 1][1] == a)
				pos = mid;
			l = mid + 1;
		} else 
		 	r = mid - 1;
	}
	return pos;
}

int bs2(int l, int r, int i) {
	int pos = 0;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (s[i][2] - s[mid - 1][2] >= b) {
			if (s[i][2] - s[mid - 1][2] == b)
				pos = mid;
			l = mid + 1;
		} else 
		 	r = mid - 1;
	}
	return pos;
}

int main() {
	//freopen("test.inp", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin >> n >> a >> b;
	for(int i=1;i<=n;i++) {
		int type;
		cin >> x[i].first >> x[i].second;
	}
	sort(x + 1, x + 1 + n);
	for(int i=1;i<=n;i++) {
		//len[i] = len[i - 1] + x[i].first;
		s[i][1] = s[i - 1][1] + (x[i].second == 1);
		s[i][2] = s[i - 1][2] + (x[i].second == 2);
//		cout << x[i].first << " " << x[i].second << endl;
	}

	//cout << s[n][1] <<" " << s[n][2] << endl;
	int res = 1e9 + 10;
	for(int i=1;i<=n;i++) {
		int pa = bs1(1, n, i);
		int pb = bs2(1, n, i);
		//cout << pa << " " << pb << endl;
		if (pa != 0 && pb != 0)
			res = min(res, x[i].first - x[min(pa, pb)].first);
	}
	if (res != 1e9 + 10)
		cout << res;
	else
		cout << "-1";
	return 0;
}