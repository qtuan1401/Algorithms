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
    int tests;
    cin >> tests;
    while (tests--) {
        int n;
        cin >> n;
        vector < int > a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        vector < int > cnt(26, 0);
        int id = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == 0) {
                cout << char(id + 'a');
                cnt[id] = 1;
                id++;
            } else {
                for (int j = 0; j < 26; j++) {
                    if (cnt[j] == a[i]) {
                        cout << char(j + 'a');
                        cnt[j]++;
                        break;
                    }
                }
            }
        }
        cout << '\n';
    }
    return 0;
}