#include <bits/stdc++.h>

using namespace std;

const int MXN = 1e5 + 10;

int n, q;
int sum[MXN];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
        sum[i] = i;
    int len = n, ll = 0;
    bool flipped = false;
	while (q--) {
        int type, l, r;
        cin >> type >> l;
        if (type == 1) {
			if (l > len - l) {
				l = len - l;
				flipped = !flipped;
			}
			if (flipped) {
				for(int i = len - l; i < len; i++)
					sum[ll + 2 * (len - l) - i] += n - sum[ll + i];
			} else {
				ll += l;
				for(int i = 0; i < l; i++) {
					sum[ll + i] -= sum[ll - i];
                }
			}
			len -= l;
		} else {
			cin >> r;
			if (flipped) {
                l = len - l;
				r = len - r;
				swap(l, r);
			}
			cout << sum[ll + r] - sum[ll + l] << '\n';
		}
	}
}
