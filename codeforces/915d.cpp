#include <bits/stdc++.h>

using namespace std;

typedef pair < int, int > II;

const int MXN = 505;

vector < II > adj[MXN];
II trace[MXN];
int vis[MXN];
int n, m, band = -1;
bool found = false;
vector < int > cycle;

void findCycle(int u) {
    if (found == true)
        return ;
    vis[u] = 1;
    //cout << u << endl;
    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i].first;
        if (adj[u][i].second == band)
            continue;
        if (vis[v] == 1) {
            
            //cout << trace[3].first << " " << 
            if (cycle.size() == 0) {
                cycle.push_back(adj[u][i].second);
                //cout << u << " * " << v << " " << adj[u][i].second << endl;
                for(int i = u; i != v; i = trace[i].first) {
                    //cout << i << " ";
                    cycle.push_back(trace[i].second);
                    //i = trace[i].first;
                }
            }
            found = true;
            return ;
        }
        if (vis[v] == 0) {
            //cout << u << " "  << v << endl;
            trace[v] = II(u, adj[u][i].second);
            findCycle(v);
        }            
    }
    vis[u] = 2;
}


int main() {
    freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(II(v, i));
    }
    //return 0;
    for(int i = 1; i <= n; i++) {
        if (!vis[i]) {
            findCycle(i);
            if (found == true)
                break;
        }
    }
    //return 0;
    if (cycle.size() == 0) {
        cout << "YES";
        return 0;
    }

    //return 0;
    //cout << band << endl;
    for(int i = 0; i < cycle.size(); i++) {
        //cout << cycle[i] << " ";
        band = cycle[i];
        found = false;
        for(int v = 1; v <= n; v++)
            vis[v] = 0;
        for(int v = 1; v <= n; v++) {
            if (vis[v] > 0)
                continue;
            findCycle(v);
        }
        if (found == false) {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
    return 0;
}