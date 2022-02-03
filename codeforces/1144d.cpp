#include <bits/stdc++.h>

using namespace std;

const int MXN = 2e5 + 10;

int a[MXN], cnt[MXN];

int main() {
    ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	int mx = 0, pos = 0;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		cnt[a[i]]++;
		if (mx < cnt[a[i]]) {
			mx = cnt[a[i]];
			pos = i;
		}
	}

    int val = a[pos];
	cout << n - mx << '\n';
	for(int i = pos - 1; i >= 0; i--) 
		if (a[i] != val)
			cout << 1 + (a[i] > val) << " " << i + 1 << " " << i + 2 << '\n';

	for(int i = pos + 1; i < n; i++) 
		if (a[i] != val)
			cout << 1 + (a[i] > val) << " " << i + 1 << " " << i << '\n';
	
	return 0;
} 