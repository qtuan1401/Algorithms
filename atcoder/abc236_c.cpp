#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector < string > s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    map < string, bool > mp;
    for (int i = 0; i < m; i++) {
        string t;
        cin >> t;
        mp[t] = 1;
    }

    for (int i = 0; i < n; i++) {
        if (mp.find(s[i]) != mp.end())
            cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}