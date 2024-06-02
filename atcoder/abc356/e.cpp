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

vector < int > cnt;

const int LIM = 1e6;

int getSum(int l, int r) {
    if (l <= 0) return r;
    if (l > r) return 0;
    return cnt[r] - cnt[l - 1];
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
        vector < int > a(n);
        cnt.resize(LIM + 5, 0);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            cnt[a[i]]++;
        }

        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());

        for (int i = 1; i < LIM + 5; i++) cnt[i] += cnt[i - 1];
        long long ans = 0;
        for (int i = 0; i < a.size(); i++) {
            long long cur = 0;
            for (int j = a[i]; j <= LIM; j += a[i]) {
                int r = min(LIM + 1, j + a[i] - 1);
                int l = min(LIM + 1, j + (j == a[i]));
                // cout << a[i] << " " << getSum(l, r) << " " << r / a[i] << endl;
                cur += 1ll * getSum(l, r) * (r / a[i]);
                // cout << cur << endl;
            }
            long long val = getSum(a[i], a[i]);
            ans += val * (val - 1) / 2;
            ans += val * cur;
        }
        cout << ans << '\n';
    }
    return 0;
}