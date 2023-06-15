#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    while (tests--) {
        int n, pos = 0;
        cin >> n;
        vector < pair < string, int > > a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i].first >> a[i].second;
            if (a[pos].second > a[i].second) {
                pos = i;
            }
        }

        for (int i = pos; i < n; i++) cout << a[i].first << '\n';
        for (int i = 0; i < pos; i++) cout << a[i].first << '\n';
    }
    return 0;
}