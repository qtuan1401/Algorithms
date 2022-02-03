#include <bits/stdc++.h>

using namespace std;

int a[5];
int n, cnt0, cnt1;
long long ans;

int main() {
	ios_base::sync_with_stdio(0);
	cin >> n;
	for(int i = 1; i <= n; i++)	{
		int x;
		cin >> x;
		a[i & 1] += x % 2;
		ans += x / 2;
	}
	cout << ans + min(a[0], a[1]);
}
