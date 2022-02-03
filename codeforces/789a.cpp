#include <bits/stdc++.h>

using namespace std;

int n, k, w, ans;

int main() {
	ios_base::sync_with_stdio(0);
    cin >> n >> k;
	for(int i = 0; i < n; i++) {
		cin >> w;
		ans += w / k + (w % k != 0);
	}
    cout << ans / 2 + ans % 2;
}