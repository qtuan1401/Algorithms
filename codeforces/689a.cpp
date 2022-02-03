#include <bits/stdc++.h>

using namespace std;

typedef pair < int, int > II;

II pos[10];
int num[5][5], a[10];
int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i <= 4; i++)
        for (int j = 0; j <= 4; j++)
            num[i][j] = -1;
    pos[0] = II(4, 2);
    num[4][2] = 0;

    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            pos[(i - 1) * 3 + j] = II(i, j);
            num[i][j] = (i - 1) * 3 + j;
        }
    }
    string s;
    cin >> s;
    for (int i = 0; i < n; i++)
        a[i] = s[i] - '0';

    vector < II > path;
    for (int i = 1; i < n; i++) {
        int u = a[i], v = a[i - 1];
        path.push_back(II(pos[u].first - pos[v].first, pos[u].second - pos[v].second));
    }

    for (int i = 0; i <= 9; i++) {
        if (i == a[0])
            continue;
        int u = pos[i].first, v = pos[i].second;
        bool found = true;
        for (int j = 0; j < path.size(); j++) {
            int nu = u + path[j].first;
            int nv = v + path[j].second;
            if (nu < 0 || nu > 4 || nv < 0 || nv > 4 || num[nu][nv] == -1) {
                found = false;
                break;
            }
            u = nu; v = nv;
        }
        if (found) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}