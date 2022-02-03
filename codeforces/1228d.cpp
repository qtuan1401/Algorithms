#include <bits/stdc++.h>

using namespace std;

const int MXN = 1e5 + 10;

set < int > s[MXN];
map < set < int >, int > mp;
int n, m, cnt;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        s[u].insert(v);
        s[v].insert(u);
    }

    for(int i = 1; i <= n; i++) {
        if (s[i].size() == 0) {
            cout << -1;
            return 0;
        }
        if (!mp[s[i]])
            mp[s[i]] = ++cnt;
    }
    if (cnt != 3) {
        cout << -1;
        return 0;
    }
    for(int i = 1; i <= n; i++)
        cout << mp[s[i]] << " ";
    return 0;
}