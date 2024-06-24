#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair < int, int > pii;

bool check(int x, int y) {
    set < int > s;
    while (x > 0) {
        s.insert(x % 10);
        x /= 10;
    }

    while (y > 0) {
        s.insert(y % 10);
        y /= 10;
    }

    return s.size() == 1;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    while (tests--) {
        int n;
        cin >> n;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            for (int j = 1; j <= x; j++) {
                if (check(i, j)) ans++;
            }
        }

        cout << ans << '\n';
    }
    return 0;
}