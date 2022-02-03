#include <bits/stdc++.h>

using namespace std;

int a[1010], cnt[2];
int main() {
    ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	int l = 0, r = n - 1;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < n; i++){
		if (a[l] > a[r])
			cnt[i % 2] += a[l++];
		else
			cnt[i % 2] += a[r--];
	}

	cout << cnt[0] << " " << cnt[1];
}