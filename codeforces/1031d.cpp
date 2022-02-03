#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e3 + 10;

typedef pair < int, int > II;

const int dx[] = {0, 1};
const int dy[] = {1, 0};

vector < II > lst, c[50];
int n, k;
string s[MAXN], res;
int f[MAXN][MAXN];
bool vis[MAXN][MAXN];

void findAns(int posMx) {
    for (int i = posMx + 1; i < n * 2 - 1; i++) {
        //cout << i << endl;
        for(int j = 0; j < 26; j++)
            c[j].clear();
        int mn = 30;
        for(int j = 0; j < lst.size(); j++) {
            int u = lst[j].first, v = lst[j].second;
            //cout << u << " " << v << endl;
            for(int id = 0; id < 2; id++) {
                int nu = u + dx[id];
                int nv = v + dy[id];
                if (nu < 0 || nu >= n || nv < 0 || nv >= n || vis[nu][nv])
                    continue;
                //cout << "(" << nu << " " << nv << " " << s[nu][nv] << ") ";
                vis[nu][nv] = true;
                c[s[nu][nv] - 'a'].push_back(II(nu, nv));
                mn = min(mn, s[nu][nv] - 'a');
            }
            //cout << endl;
        }
        lst.clear();
        if (c[mn].size())
            res = res + char(mn + 'a');
        //cout << "*" << mn << " " << c[mn].size() << endl;
        for(int j = 0; j < c[mn].size(); j++) 
            lst.push_back(c[mn][j]);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    for(int i = 0; i < n; i++) 
        cin >> s[i];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            f[i][j] = (s[i][j] != 'a');
            int mn = 1e9;
            if (i - 1 >= 0)
                mn = f[i - 1][j];
            if (j - 1 >= 0)
                mn = min(mn, f[i][j - 1]);
            if (mn != 1e9)
                f[i][j] += mn;
        }
    }
    int posMx = -1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            if (f[i][j] <= k)
                posMx = max(posMx, i + j);
    }
    for(int i = 0; i <= posMx; i++)
        res = res + "a";
    lst.clear();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            if (f[i][j] == k && i + j == posMx) {
                //cout << i << " " << j << endl;
                lst.push_back(II(i, j));
            } 
    }
    if (f[n - 1][n - 1] <= k) {
        for(int i = 0; i < 2 * n - 1; i++)
            cout << "a";
        return 0;
    }
    if (lst.empty()) {
        lst.push_back(II(0, 0));
        res = res + s[0][0];
    }
    //return 0;
    //cout << posMx << endl;
    findAns(posMx);
    cout << res;
    return 0;
}