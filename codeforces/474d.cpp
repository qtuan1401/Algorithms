#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
const int MXN = 1e5 + 10;

int f[MXN];

int main() {
    ios_base::sync_with_stdio(0);
    int n, k;
	cin >> n >> k;
	f[0] = 1;
	for(int i = 1; i < MXN; i++) {
		f[i] = f[i - 1];
		if (i >= k)
			f[i] = (f[i] + f[i - k]) % MOD;
	}
    for(int i = 0; i < MXN; i++) {
        f[i] = (f[i] + f[i - 1]) % MOD;
    }
    while (n--) {
        int l, r;
        cin >> l >> r;
        cout << (f[r] - f[l - 1] + MOD) % MOD << '\n';
    }
    return 0;
}