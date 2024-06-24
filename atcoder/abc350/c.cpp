#include <bits/stdc++.h>

using namespace std;

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
        vector < int > a(n), pos(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i]--;
            pos[a[i]] = i;
        }

        vector < pii > ans;
        for (int i = 0; i < n; i++) {
            if (a[i] != i) {
                ans.push_back(pii(i + 1, pos[i] + 1));
                pos[a[i]] = pos[i];
                a[pos[i]] = a[i];
            }
        }

        cout << ans.size() << '\n';
        for (int i = 0; i < ans.size(); i++) cout << ans[i].first << " " << ans[i].second << '\n';
    }
    return 0;
}