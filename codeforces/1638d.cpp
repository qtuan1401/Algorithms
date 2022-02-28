#include <bits/stdc++.h>

using namespace std;

struct Pairs {
    int i, j, c;
    Pairs(int _i = 0, int _j = 0, int _c = 0) {
        i = _i;
        j = _j;
        c = _c;
    }
};

const int dx[] = {0, 0, 1, 1};
const int dy[] = {0, 1, 0, 1};

vector < Pairs > ans;
vector < vector < int > > cur, final;
int n, m;

void color(int i, int j, int c) {
    // cout << i << " * " << j << " " << c << endl;
    for (int k = 0; k < 4; k++) {
        int ni = i + dx[k];
        int nj = j + dy[k];
        // cout << i << " * " << j << " * " << ni << " * " << nj << endl;
        cur[ni][nj] = c;
    }
}

int change(int i, int j) {
    int res = 0;
    for (int k = 0; k < 4; k++) {
        int ni = i + dx[k];
        int nj = j + dy[k];
        if (cur[ni][nj] != final[ni][nj]) {
            res = final[ni][nj];
            break;
        }
    }
    return res;
}

bool tryColor(int i, int j) {
    if (i == m - 1 || j == m - 1) return false;
    cout << i << " * " << j << endl;
    for (int k = 0; k < n - 1; k++) {
        cur[k][i] = final[k][i];
    }
    
    
    for (int k = 0; k < n - 1; k++)
        if (int c = change(k, j))
            color(k, j, c);

    // cout << i << " * " << j << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << cur[i][j] << " ";
        cout << endl;
    }
    
    bool res = true;

    for (int k = 0; k < n; k++) {
        res &= (cur[k][i] == final[k][i]);
        res &= (cur[k][j] == final[k][j]);
        cur[k][i] = cur[k][j] = 0;
    }

    if (i == m - 2 || j == m - 2) {
        for (int k = 0; k < n; k++)
            res &= (cur[k][m - 1] == final[k][m - 1]);
    }

    // cout << res << endl;
    return res;
}

int main() {
    freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    final.resize(n, vector < int > (m));
    cur.resize(n, vector < int > (m, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> final[i][j];

    for (int i = 0; i < n - 1; i++)
        if (cur[i][0] != final[i][0]) {
            color(i, 0, final[i][0]);
            ans.push_back(Pairs(i, 0, final[i][0]));
        }
    if (m > 2) {
        vector < int > l(m), r(m);
        for (int j = 1; j < m - 2; j++) {
            bool resl = tryColor(j, j + 1);
            if (resl)
                r[j] = 1;
            else l[j + 1] = 1;
        }
        for (int j = 1; j < m - 1; j++) 
            if (l[j] != 0) l[j] += l[j - 1];
        for (int j = m - 2; j >= 1; j--)
            if (r[j] != 0) r[j] += r[j + 1];

        vector < pair < int, int > > val(m, {-1, -1});
        for (int j = 1; j < m - 1; j++) {
            val[j].first = max(l[j], r[j]);
            val[j].second = j;
            // cout << l[j] << " " << r[j] << endl;
        }

        sort(val.begin(), val.end());
        for (int k = 0; k < val.size(); k++) {
            int j = val[k].second;
            if (j == -1) continue;
            for (int i = 0; i < n - 1; i++) {
                color(i, j, final[i][j]);
                ans.push_back(Pairs(i, j, final[i][j]));
            }
        }
    }
    bool ok = true;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (cur[i][j] != final[i][j]) {
                ok = false;
                break;
            }

    if (!ok) 
        cout << "-1\n";
    else {
        cout << ans.size() << '\n';
        for (Pairs e : ans)
            cout << e.i << " " << e.j << " " << e.c << '\n';
    }
    return 0;
}