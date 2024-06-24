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
    int tests;
    cin >> tests;
    while (tests--) {
        int n;
        cin >> n;
        vector < int > a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());

        int cnt = 0;
        for (int i = 0; i < a.size(); i++) {
            // cout << a[i] << " ";
            if (cnt + 1 == a[i]) cnt++;
            else break;
        }

        if (cnt == a.size()) {
            if (cnt % 2 != 0) cout << "Alice\n";
            else cout << "Bob\n";
            continue;
        }

        // cout << cnt << '\n' << endl;
        if (cnt % 2 != 0) cout << "Bob\n";
        else cout << "Alice\n";
    }
    return 0;
}