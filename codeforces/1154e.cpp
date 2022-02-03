#include <bits/stdc++.h>

using namespace std;

const int md = 2e5 + 10;

int n, k;
int ans[md], pos[md], rr[md], ll[md];

int main() {
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        pos[x] = i;
		ll[i] = i - 1;
		rr[i] = i + 1;
    }
    int id = 1;
    for(int j = n; j >= 1; j--) {
        int i = pos[j];
        if (ans[i] > 0)
            continue;
        id ^= 1;
        ans[i] = id + 1;
		int l = ll[i], r = rr[i];
        for(int ii = 1; ii <= k && l; ii++) {
			ans[l] = id + 1;
			l = ll[l];
		}
		for(int ii = 1; ii <= k && r <= n; ii++) {
			ans[r] = id + 1;
			r = rr[r];
		}
		ll[r] = l; rr[l] = r;
    }
    for(int i = 1; i <= n; i++)
        cout << ans[i];
    return 0;
}
