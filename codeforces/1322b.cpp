#include<bits/stdc++.h>

using namespace std;

const int MXN = 4e5 + 10;

int a[MXN], b[MXN];
int n, k;

int main() {
	ios_base::sync_with_stdio(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);

    long long ans = 0;
	for(int k = 0; k <27 ; k++) {
		for(int i = 0; i < n; i++)
			b[i] = a[i] % (1 << (k + 1));

		sort(b, b + n);
        long long cnt = 0;
		for(int i = 0; i < n; i++) {
			int l = lower_bound(b + i + 1, b + n, (1 << k) - b[i]) - b;
			int r = lower_bound(b + i + 1, b + n, (1 << (k + 1)) - b[i]) - b;
			cnt += r - l;
			l = lower_bound(b + i + 1, b + n, (1 << (k + 1)) + (1 << k) - b[i]) - b;
			cnt += n - l;
		}
		ans += (cnt % 2) * 1ll * (1 << k);
	}

	cout << ans << "\n";
	return 0;
}
