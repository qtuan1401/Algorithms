#include <bits/stdc++.h>

using namespace std;

const int LIM = 2e5 + 10;

int d[LIM];
int n;
vector < int > adj[LIM];

void bfs(int s) {
    queue < int > qu;
    qu.push(s);
    d[s] = 1;
    while (qu.size()) {
        int u = qu.front(); qu.pop();
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            if (d[v])
                continue;
            d[v] = d[u] + 1;
            qu.push(v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        adj[i].push_back(x);
    }
    
    for (int i = 1; i < n; i++) {
        adj[i].push_back(i + 1);
        adj[i + 1].push_back(i);
    }

    bfs(1);

    for (int i = 1; i <= n; i++)
        cout << d[i] - 1 << " ";
    return 0;
} 