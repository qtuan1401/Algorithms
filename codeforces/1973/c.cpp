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

int calc(vector < int > a, int type) {
    vector < int > c;
    int n = a.size();
    for (int i = type; i < n; i += 2) {
        c.push_back(a[i]);
    }

    vector < int > ans(n);
    sort(c.begin(), c.end());
    for (int i = type; i < n; i += 2) {
        ans[i] = n / 2 - (lower_bound(c.begin(), c.end(), a[i]) - c.begin());
    }
    c.clear();
    for (int i = 1 - type; i < n; i += 2) {
        c.push_back(a[i]);
    }
    sort(c.begin(), c.end());
    for (int i = 1 - type; i < n; i += 2) {
        ans[i] = n - (lower_bound(c.begin(), c.end(), a[i]) - c.begin());

    }

    int res = 0;
    for (int i = 1; i < n - 1; i++) {
        res += (ans[i] + a[i] > ans[i - 1] + a[i - 1] && ans[i] + a[i] > ans[i + 1] + a[i + 1]);
    }
    // for (int i = 0; i < n; i++) cout << ans[i] << " ";
    // cout << endl;
    // cout << res << endl;
    return res;
}

vector < int > trc(vector < int > a, int type) {
    vector < int > c;
    int n = a.size();
    for (int i = type; i < n; i += 2) {
        c.push_back(a[i]);
    }

    vector < int > ans(n);
    sort(c.begin(), c.end());
    for (int i = type; i < n; i += 2) {
        ans[i] = n / 2 - (lower_bound(c.begin(), c.end(), a[i]) - c.begin());
    }
    c.clear();
    for (int i = 1 - type; i < n; i += 2) {
        c.push_back(a[i]);
    }
    sort(c.begin(), c.end());
    for (int i = 1 - type; i < n; i += 2) {
        ans[i] = n - (lower_bound(c.begin(), c.end(), a[i]) - c.begin());

    }
    return ans;
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
        cin >> n;
        vector < int > a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        vector < int > ans(n);
        if (calc(a, 0) > calc(a, 1)) ans = trc(a, 0);
        else ans = trc(a, 1);
        for (int i = 0; i < n; i++) cout << ans[i] << " ";
        cout << '\n';
    }
    return 0;
}