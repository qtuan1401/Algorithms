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

const long long INF = 1e9 + 10;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests;
    cin >> tests;
    while (tests--) {
        int n;
        cin >> n;
        vector < int > a(n), b(n + 1);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i <= n; i++) cin >> b[i];

        long long ans = 0;
        long long step = INF;
        for (int i = 0; i < n; i++) {
            ans += abs(a[i] - b[i]);
            long long temp = abs(b[n] - b[i]) + 1;
            if (b[i] == b[n]) temp = 1;
            else if (min(b[i], a[i]) > b[n]) temp = 1 + min(a[i], b[i]) - b[n];
            else if (max(a[i], b[i]) < b[n]) temp = 1 + b[n] - max(a[i], b[i]);
            else if (a[i] <= b[n] && b[n] <= b[i]) temp = 1;
            else if (b[i] <= b[n] && b[n] <= a[i]) temp = 1;

            step = min(step, temp);
        }

        cout << ans + step << '\n';
    }
    return 0;
}