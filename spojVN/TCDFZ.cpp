#include <bits/stdc++.h>

using namespace std;

int n;
int dig[] = {1, 1, 2, 6, 4, 2, 2, 4, 2, 8};

int get(int n) {
	if (n < 10)
		return dig[n];

	if (((n / 10) % 10) % 2 == 0) 
		return (6 * get(n / 5) * dig[n % 10]) % 10;
	else 
		return (4 * get(n / 5) * dig[n % 10]) % 10;
}

main() {
	//freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin >> n;
	//cout << n << endl;
	cout << get(n);
//	return 0;
}