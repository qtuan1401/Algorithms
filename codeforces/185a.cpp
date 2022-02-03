#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int calc(long long a, long long n) {
    long long res = 1;
    while (n > 0) {
        if (n & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        n /= 2;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
	long long n;
    cin >> n;
	long long x = calc(2, n);
    cout << x * (x + 1) / 2 % MOD;
	return 0;
}