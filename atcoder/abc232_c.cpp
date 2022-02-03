#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;

    vector < vector < bool > > tieA(n, vector < bool > (n, 0)), tieB(n, vector < bool > (n, 0));

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        tieA[x][y] = tieA[y][x] = 1;
    }

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        tieB[x][y] = tieB[y][x] = 1;
    }

    vector < int > id(n, 0);
    for (int i = 0; i < n; i++)
        id[i] = i;
    
    bool res = false;
    do {
        bool ok = true;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (tieA[i][j] != tieB[id[i]][id[j]]) {
                    ok = false;
                    break;
                }
        res |= ok;
    } while (next_permutation(id.begin(), id.end()));
    if (res) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}