#include <bits/stdc++.h>

using namespace std;

const int oo = 1e9 + 7;
const int md = 2e3 + 5;

struct node {
    int x, y, l, r;
};

typedef pair < int, int > II;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int n, m, r, c, LL, RR, res;
deque < node > dq;
string s[md];

void dijsktra(int xx, int yy) {
    dq.push_back({xx, yy, LL, RR});
    s[xx][yy] = '*';
    while (dq.size()) {
        node cur = dq.front(); dq.pop_front();
        int u = cur.x, v = cur.y, l = cur.l, r = cur.r;
        if (l < 0 || r < 0)
            continue;
        res++;
        //cout << u << " " << v << " " << f[u][v] << endl;
        for(int i = 0; i < 4; i++) {
            int nu = u + dx[i], nv = v + dy[i];
            if (nu < 1 || nu > n || nv < 1 || nv > m || s[nu][nv] == '*')
                continue;
            s[nu][nv] = '*';
            if (i == 1 || i == 3)
                dq.push_back({nu, nv, l - (i == 3), r - (i == 1)});
            else dq.push_front({nu, nv, l, r});
            
        }
    }
}

int main() {
 //   freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    cin >> r >> c;
    cin >> LL >> RR;
    for(int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] = "#" + s[i];
    }
    dijsktra(r, c);
    cout << res;
    return 0;
}