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
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    while (tests--) {
        int n;
        cin >> n;
        vector < int > l(n), r(n);
        vector < int > id(n);
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> l[i] >> r[i];
            r[i] -= l[i];
            sum += l[i];
            id[i] = i;
        }

        if (sum > 0) cout << "No\n";
        else {
            vector < int > ans(n, 0);
            sort(id.begin(), id.end(), [&](int i, int j) {
                return r[i] > r[j];
            });
            for (int i = 0; i < n && sum != 0; i++) {
                if (sum + r[id[i]] < 0) {
                    sum += r[id[i]];
                    ans[id[i]] = r[id[i]];
                } else {
                    ans[id[i]] = -sum;
                    sum = 0;
                }
            }
            if (sum != 0) cout << "No\n";
            else {
                for (int i = 0; i < n; i++) ans[i] += l[i];
                cout << "Yes\n";
                for (int i = 0; i < n; i++) cout << ans[i] << " ";
                cout << '\n';
            }
        }
    }
    return 0;
}