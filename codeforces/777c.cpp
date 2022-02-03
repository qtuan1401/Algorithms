#include <bits/stdc++.h>

using namespace std;

const int MXN = 1e5 + 10;

vector < vector < int > > a, pos;
int mn[MXN];

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    a.resize(n, vector < int > (m));
    pos.resize(n, vector < int > (m));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
    for(int j = 0; j < m; j++)
        pos[0][j] = 0;
    for(int i = 0; i < n; i++)
        mn[i] = n + 1;
    mn[0] = 0;
    for(int j = 0; j < m; j++) {
        for(int i = 1; i < n; i++) {
            pos[i][j] = i;
            if (a[i - 1][j] <= a[i][j]) 
                pos[i][j] = pos[i - 1][j];
            mn[i] = min(mn[i], pos[i][j]);
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        if (mn[r] <= l)
            cout << "Yes\n";
        else 
            cout << "No\n";
    }
    return 0;
}