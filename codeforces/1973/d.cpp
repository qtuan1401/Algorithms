#include <bits/stdc++.h>

using namespace std;

template < class T >
void resetVec(vector < T > & a, int sz, T val) {
    a.clear();
    a.resize(sz, val);
}

typedef long double ld;
typedef long long ll;
typedef pair < int, int > pii;

int main() {
    // #ifndef ONLINE_JUDGE
    // freopen("../test.in", "r", stdin);
    // #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests;
    cin >> tests;
    while (tests--) {
        int n, k;
        cin >> n >> k;
        long long sum = 0;
        for (int i = 1; i <= n; i++) {
            long long val = 1ll * n * i;
            cout << "? " << 1 << " " << val << endl;
            int r;
            cin >> r;
            if (r == n) {
                sum = val;
                break;
            }
        }
        
        long long mx = sum / n, ans = -1;
        for (int i = n / k; i >= 1; i--) {
			int cnt = k, l = 1;
			while (l <= n && cnt > 0) {
                cout << "? " << l << " " << i * mx << endl;
				int r;
                cin >> r;
				if (r == n + 1) break;
                cnt--;
				l = r + 1;
			}
			if (l == n + 1 && cnt == 0) {
                ans = i * mx;
                break;
            }
		}
        cout << "! " << ans << endl;
        cin >> mx;
    }
    return 0;
}