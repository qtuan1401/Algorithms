#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector < int > a(n);
    int cnt = 0;
    map < int, int > mp;
    vector < vector < int > > pos(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (mp.find(a[i]) == mp.end())
            mp[a[i]] = cnt++;
        pos[mp[a[i]]].push_back(i);
    }

    while (q--) {
        int x, k;
        cin >> x >> k;
        if (mp.find(x) == mp.end()) {
            cout << "-1\n";
            continue;
        }
        x = mp[x];
        if (k > pos[x].size()) cout << "-1\n";
        else cout << pos[x][k - 1] + 1 << '\n';
    }
    return 0;
}