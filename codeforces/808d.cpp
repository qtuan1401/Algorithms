#include <bits/stdc++.h>

using namespace std;

const int MXN = 1e5 + 10;

int n;
int a[MXN];
long long sum;
map < long long, bool > mp;

void solve() {
    mp.clear();
    long long cur = 0;
	for (int i = 0; i < n; i++) {
		cur += a[i]; 
        mp[a[i]] = 1;
		if (mp.count(cur - sum)) {
            cout << "YES";
            exit(0);
        }
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    if (sum & 1) {
        cout << "NO";
        return 0;
    }

    sum /= 2;
    solve();
    reverse(a, a + n);
    solve();

    cout << "NO";
    return 0;
}