#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        cout << 1 + (n * 4) / __gcd(n * 4, n + 1) << '\n';
    }
	return 0;
}