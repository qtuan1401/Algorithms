#include <bits/stdc++.h>

using namespace std;

vector < int > a;
int n;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        a.resize(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        reverse(a.begin(), a.end());
        a.push_back(a[0]);
        int r = 0, res = 0;
        while (r < n) {
            while (r < n && a[r] == a[0]) r++;
            r = min(r, (n + 1) / 2);
            int cnt = 0;
            for (int i = 0; i < r; i++)
                cnt |= (a[i] != a[i + r]);
            r *= 2;
            for (int i = 0; i < r; i++)
                a[i] = a[0];
            res += cnt;
        }
        cout << res << '\n';
    }
    return 0;
}