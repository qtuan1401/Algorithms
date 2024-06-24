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

vector < int > fw;
int n;

long long get(int x) {
    long long ans = 0;
    while (x > 0) {
        ans += fw[x];
        x -= (x & (-x));
    }
    return ans;
}

void update(int x) {
    while (x <= n + 1) {     
        fw[x]++;
        x += (x & (-x));   
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    while (tests--) {
        cin >> n;
        fw.resize(n + 10, 0);
        vector < int > a(n), sa(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sa[i] = a[i];
        }

        sort(sa.begin(), sa.end());
        sa.erase(unique(sa.begin(), sa.end()), sa.end());

        vector < int > smaller(n), bigger(n);
        for (int i = 0; i < n; i++) {
            int pos = lower_bound(sa.begin(), sa.end(), a[i]) - sa.begin() + 1;
            smaller[i] = get(pos);
            update(pos + 1);
        }

        for (int i = 0; i < n + 10; i++) fw[i] = 0;
        for (int i = n - 1; i >= 0; i--) {
            int pos = lower_bound(sa.begin(), sa.end(), a[i]) - sa.begin() + 1;
            // cout << (n - i - 1) << " " << get(pos + 1) << endl;
            bigger[i] = (n - i - 1) - get(pos + 1);
            update(pos + 1);
        }

        // for (int i = 0; i < n; i++) cout << smaller[i] << " ";
        // cout << endl;
        // for (int i = 0; i < n; i++) cout << bigger[i] << " ";
        // cout << endl;

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += 1ll * smaller[i] * a[i];
            ans -= 1ll * bigger[i] * a[i];
        }

        cout << ans << '\n';
    }
    return 0;
}