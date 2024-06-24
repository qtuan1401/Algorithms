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
        int n, m;
        cin >> n >> m;
        vector < pii > a(n + m);
        for (int i = 0; i < n; i++) {
            cin >> a[i].first;
            a[i].second = 0;
        }

        for (int i = n; i < n + m; i++) {
            cin >> a[i].first;
            a[i].second = 1;
        }

        sort(a.begin(), a.end());

        bool found = false;
        for (int i = 1; i < n + m; i++) {
            if (a[i].second == 0 && a[i - 1].second == 0) {
                found = true;
                break;
            }
        }

        if (found) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}