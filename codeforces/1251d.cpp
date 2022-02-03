#include <bits/stdc++.h>

using namespace std;

const int md = 2e5 + 10;

int T, n;
pair < int, int > a[md];
long long s;

bool check(int x) {
    int need = n / 2 + 1;
    long long budget = s;
    //cout << budget << endl;
    for(int i = 1; i <= n; i++)
        need -= (a[i].first >= x);
    for(int i = n; i >= 1; i--)
        if (a[i].first < x && x <= a[i].second && budget - (x - a[i].first) >= 0) {
            budget -= (x - a[i].first);
            need--;
        }

    return (need <= 0);
}

int bs(int l, int r) {
    int res = -1;

    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            res = mid;
            l = mid + 1;
        } else r = mid - 1;
    }

    return res;
}

int main() {
    //freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> T;
    while (T--) {
        cin >> n >> s;
        for(int i = 1; i <= n; i++) { 
            cin >> a[i].first >> a[i].second;
            s -= a[i].first;
        }
        sort(a + 1, a + 1 + n);

        cout << max(a[n / 2 + 1].first, bs(a[n / 2 + 1].first + 1, 1e9)) << '\n';
    }
    return 0;
}