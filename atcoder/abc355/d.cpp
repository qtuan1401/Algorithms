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

vector < int > fw, val;

void update(int x) {
    while (x <= val.size()) {
        fw[x] += 1;
        x += (x & (-x));
    }
}

int get(int x) {
    int res = 0;
    while (x > 0) {
        res += fw[x];
        x-= (x & (-x));
    }
    return res;
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
        vector < pii > a(n);
        val.push_back(-1);
        for (int i = 0; i < n; i++) {
            cin >> a[i].first >> a[i].second;
            val.push_back(a[i].first);
            val.push_back(a[i].second);
        }
        sort(val.begin(), val.end());
        val.erase(unique(val.begin(), val.end()), val.end());

        fw.resize(val.size() + 5, 0);

        sort(a.begin(), a.end());

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int l = lower_bound(val.begin(), val.end(), a[i].first) - val.begin();
            // cout << i - get(l - 1) << endl;
            ans += i - get(l - 1);

            int r = lower_bound(val.begin(), val.end(), a[i].second) - val.begin();
            update(r);
        }

        cout << ans << '\n';
    }
    return 0;
}