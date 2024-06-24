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

bool calc(int n, long long val) {
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += abs(i - (n - i - 1));
    }
    if (sum >= val) return true;
    return false;
}

int bs(int l, int r, long long val) {
    int pos = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (calc(mid, val)) {
            pos = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    return pos;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests;
    cin >> tests;
    while (tests--) {
        int n;
        long long k;
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int s1 = abs(i - (n - i - 1)) + abs(j - (n - j - 1));
                int s2 = abs(i - (n - j - 1)) + abs(j - (n - i - 1));
                if (s1 - s2 == 4) cout << i << " " << j << endl;
            }
        }
        // if (k & 1) {
        //     cout << "No\n";
        //     continue;
        // }
        // int m = bs(1, n, k);
        // if (m == -1) cout << "No\n";
        // else {
        //     cout << "Yes\n";
        //     vector < int > ans(n);
        //     long long sum = 0;
        //     for (int i = 0; i < m; i++) {
        //         ans[i] = m - i - 1;
        //         sum += abs(ans[i] - i);
        //     }
        //     cout << m << " " << sum << " " << k << endl;
        //     swap(ans[m / 2 - (sum - k) / 2], ans[m / 2]);
        //     for (int i = m; i < n; i++) ans[i] = i;
        //     for (int i = 0; i < n; i++) cout << ans[i] + 1 << " ";
        //     cout << '\n';
        //     sum = 0;
        //     for (int i = 0; i < n; i++) {
        //         sum += abs(ans[i] - i);
        //     }
        //     cerr << sum << endl;
        // }
    }
    return 0;
}