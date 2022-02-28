#include <bits/stdc++.h>

using namespace std;

bool check(int x, vector < int > & a) {
    vector < int > b;
    for (int i = 0; i < a.size(); i++)
        if (a[i] != x)
            b.push_back(a[i]);
    int n = b.size();
    for (int i = 0; i < n; i++)
        if (b[i] != b[n - 1 - i]) return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector < int > a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        bool ok = true;
        for (int i = 0; i < n; i++)
            if (a[i] != a[n - 1 - i]) {
                ok = check(a[i], a) || check(a[n - 1 - i], a);
                break;
            }
        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}