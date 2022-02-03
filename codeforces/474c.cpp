#include <bits/stdc++.h>

using namespace std;

long long x[20], y[20], f[10];

inline long long calcDst(int i, int j) {
	return (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
}

int solve() {
    int res = 1e9;
    for(int i = 0; i < 4; i++) {
        for(int j = 4; j < 8; j++) {
            for(int u = 8; u < 12; u++) {
                for(int v = 12; v < 16; v++) {
                    f[0] = calcDst(i, j); f[1] = calcDst(i, u); f[2] = calcDst(i, v);
                    f[3] = calcDst(j, u); f[4] = calcDst(j, v); f[5] = calcDst(u, v);
                    sort(f, f + 6);
                    if (f[0] == f[3] && f[0] * 2 == f[5] && f[4] == f[5] && f[0] != 0)
                        res = min(res, i + j + u + v - 24);
                }
            }
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    int n;
	cin >> n;
	while (n--) {
        int a1, b1, a2, b2;
		for(int i = 0; i < 4; i++) {
            cin >> a1 >> b1 >> a2 >> b2;
            a1 -= a2; b1 -= b2;
			x[i * 4] = a1; y[i * 4] = b1;
			for(int j = 1; j < 4; j++) {
				x[i * 4 + j] =  -y[i * 4 + j - 1]; 
                y[i * 4 + j] =  x[i * 4 + j - 1];
            }
            for(int j = 0; j < 4; j++) {
                x[i * 4 + j] += a2;
                y[i * 4 + j] += b2;
            }
		}
        int ans = solve();
        if (ans == 1e9)
            cout << "-1\n";
        else
            cout << ans << '\n';
	}
}
