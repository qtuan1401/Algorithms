#include <bits/stdc++.h>

using namespace std;

long long a, b, t, m, l;

inline long long calc(long long x) {
    return x * (a * 2 + (x - 1) * b) / 2;
}

int bs(int p, int l, int r) {
    int ans = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (a + (mid - 1) * b <= t && calc(mid) - calc(p - 1) <= m * t) {
            ans = mid;
            l = mid + 1;
        } else
            r = mid - 1;
    }
    return ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q;
	cin >> a >> b >> q;

	while (q--) {
		cin >> l >> t >> m;
        cout << bs(l, l, 2e6) << '\n';
	}
}
