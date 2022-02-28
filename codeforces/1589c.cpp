#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector < int > a(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        
        for (int i = 0; i < n; i++)
            cin >> b[i];

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        bool res = true;
        for (int i = 0; i < n; i++)
            if (a[i] > b[i] || a[i] + 1 < b[i]) res = false;

        if (res) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}