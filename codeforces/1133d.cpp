#include <bits/stdc++.h>

using namespace std;

const int MXN = 2e5 + 10;

typedef pair < int, int > II;

int n, res, cnt;
int a[MXN];
map < II, int> mp;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
	for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt += (a[i] == 0 && b == 0);
        int gcd = __gcd(a[i], b);
        II p = II(b / gcd, a[i] / gcd);
        if (a[i]) {
            res = max(res, ++mp[p]);
        }
	}
    cout << res + cnt << '\n';
    return 0;
}