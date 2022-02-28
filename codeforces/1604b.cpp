#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector < int > a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        if (n % 2 == 0) cout << "YES\n";
        else {
            bool found = false;
            for (int i = 0; i < n - 1; i++)
                found |= (a[i] >= a[i + 1]);
            if (found) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}