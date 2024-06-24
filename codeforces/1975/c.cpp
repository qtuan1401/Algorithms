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
        if (n == 1) {
            cout << a[0] << '\n';
            continue;
        } 
        if (n == 2) {
            cout << min(a[0], a[1]) << '\n';
            continue;
        }
        int ans = 0;
        for (int i = 0; i < n - 2; i++) {
            vector < int > temp;
            for (int j = i; j <= i + 2; j++) {
                temp.push_back(a[j]);
            }
            sort(temp.begin(), temp.end());
            ans = max(ans, temp[1]);
        }
        cout << ans << '\n';
    }
    return 0;
}