#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;

set < int > unMarked, adj[MAXN];
queue < int > q;
vector < int > g;
int n, m, cnt;


void bfs(int u) {
    q.push(u);
    set < int > :: iterator it = unMarked.find(u);
    unMarked.erase(it);
    while (q.size()) {
        cnt++;
        int u = q.front();
        q.pop();
        vector < int > temp;
        for(it = unMarked.begin(); it != unMarked.end(); it++)
            if (adj[u].find(*it) == adj[u].end()) {
                q.push(*it);
                temp.push_back(*it);
            }
        for(int i = 0; i < temp.size(); i++)
            unMarked.erase(unMarked.find(temp[i]));
    }
}

int main() {
    //freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    for(int i = 1; i <= n; i++)
        unMarked.insert(i);

    for(int i = 1; i <= n; i++)
        if (unMarked.find(i) != unMarked.end()) {
            cnt = 0;
            bfs(i);
            g.push_back(cnt);
        }
    int sum = 0;
    sort(g.begin(), g.end());
    cout << g.size() << '\n';
    for(int i = 0; i < g.size(); i++) {
        cout << g[i] << " ";
    }
    return 0;   
}