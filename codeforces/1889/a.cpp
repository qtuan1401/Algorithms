#include <bits/stdc++.h>

#define vall(a) (a.begin(), a.end())

using namespace std;

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
        vector < int > cnt(200000), a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            cnt[a[i]]++;
        }
        sort(a.begin(), a.end());

        a.erase(unique(a.begin(), a.end()), a.end());

        if (a.size() == 1) {
            cout << "YES\n";
        } else if (a.size() == 2) {
            if (abs(cnt[a[0]] - cnt[a[1]]) <= 1) cout << "YES\n";
            else cout << "NO\n";
        } else cout << "NO\n";
    }
    return 0;
}