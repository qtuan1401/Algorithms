#include <bits/stdc++.h>
#define REP(i, n) for(int i = 1; i <= n; i++)
#define FOR(i, a, b) for(int i = a; i < b; i++)
const int MAXN = 1e5 * 5;
const int INF = 1e9 + 7;
using namespace std;
int d[100][100];
int w[100][100];
string s;
typedef pair<int, int> ii;
int x[101];
ii p[110];
vector< ii > v;
int pos[11];
int dist[100][100];
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("key.inp", "r", stdin);
    //freopen("key.out", "w", stdout);
    REP(i, 9)
        x[i] = i;
    x[10] = 0;
    cin >> s;
    //cout<<s<<endl;
    FOR(i, 0, s.size() - 1){
        d[s[i] - '0'][s[i + 1] - '0']++;
        if (d[s[i] - '0'][s[i + 1] - '0'] == 1) v.push_back(ii(s[i] - '0', s[i + 1] - '0'));
    }
    p[1].first = 1; p[1].second = 1;
    p[2].first = 1; p[2].second = 2;
    p[3].first = 1; p[3].second = 3;
    p[4].first = 2; p[4].second = 1;
    p[5].first = 2; p[5].second = 2;
    p[6].first = 2; p[6].second = 3;
    p[7].first = 3; p[7].second = 1;
    p[8].first = 3; p[8].second = 2;
    p[9].first = 3; p[9].second = 3;
    p[10].first = 4; p[10].second = 1;
    REP(u, 10)
        REP(v, 10) dist[u][v] = abs(p[u].first - p[v].first) + abs(p[u].second - p[v].second);
    int ans = INF;
    while (next_permutation(x + 1, x + 11)) {
        int sum = 0;
        REP(i, 10) pos[x[i]] = i;
        FOR(i, 0, v.size()) {
            int u = v[i].first, vv = v[i].second;
            sum += dist[pos[u]][pos[vv]] * d[u][vv];
        }
        ans = min(ans, sum);
    }
    cout << ans;
    return 0;
}
