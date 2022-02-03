#include<bits/stdc++.h>

using namespace std;

const int MXN = 1e3 + 10;
const int MOD = 1e9 + 7;

long long f[MXN], p[MXN];

int main() {
    ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) 
        cin >> p[i];

	f[0] = 0;
	for (int i = 0; i < n; i++) 
        f[i + 1] = (f[i] * 2 + 2 - f[p[i] - 1] + MOD) % MOD;
	cout << f[n];
}
