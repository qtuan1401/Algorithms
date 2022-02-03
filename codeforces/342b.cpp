#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
	int n, m, s, f;

	cin >> n >> m >> s >> f;
	char c = 'L';
	int drt = -1;

	if (s < f) {
		c = 'R';
        drt = 1;
    }
    cout << c << " " << drt << endl;
	int cur = s, p = 1, cnt = 0;
	while (cur != f) {
		int t, l, r;
		if (cnt < m) {
			cin >> t >> l >> r;
			cnt++;
		}
		while (p < t) {
			cur += drt;
			cout << c;
			if (cur == f)
				return 0;
			p++;
		}
		//cout << p << " " << t << " " << cur << " " << drt << endl;
		if ((p == t) && ((l <= cur && cur <= r) || (l <= cur + drt && cur + drt <= r)))
			cout << "X";
		else {
			cout << c;
			cur += drt;
		}
		p++;
	}
	return 0;
}
