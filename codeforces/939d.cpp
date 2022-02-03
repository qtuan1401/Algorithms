#include <bits/stdc++.h>

using namespace std;

const int MXN = 30;

string s, t;
int vis[MXN];
vector < pair < int, int > > ans;
vector < int > adj[MXN];
int n;

void dfs(int u) {
    vis[u] = true;
    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (vis[v])
            continue;
        dfs(v);
        ans.push_back(make_pair(v, u));
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    cin >> s >> t;
    for(int i = 0; i < n; i++) {
        if (s[i] != t[i]) {
            int u = s[i] - 'a';
            int v = t[i] - 'a';
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    for(int i = 0; i < 26; i++)
        if (!vis[i])
            dfs(i);
    cout << ans.size() << '\n';
    for(int i = 0; i < ans.size(); i++)
        cout << char(ans[i].first + 'a') << " " << char(ans[i].second + 'a') << '\n';

    return 0;
}