#include <bits/stdc++.h>

using namespace std;

int n, m;
map < string, string > mp;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        string a, b;
        cin >> a >> b;
        mp[a] = b;
    }
    for(int i = 0; i < n; i++) {
        string a;
        cin >> a;
        if (mp[a].size() < a.size())
            cout << mp[a];
        else
            cout << a;
        cout << " ";
    }
}