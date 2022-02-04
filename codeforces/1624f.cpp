#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
typedef pair<int,ii> iii;

vector < int > lab;
vector < iii > graph;
int n,m;
long long int s;

int root(int i) {
    if (lab[i] < 0)
        return i;
    return lab[i] = root(lab[i]);
}

bool merge(int x, int y) {
    if ((x = root(x)) == (y = root(y)))
        return false;
    if (lab[y] < lab[x])
        swap(x, y);
    lab[x] += lab[y];
    lab[y] = x;
    return true;
}

int res = 0;

void kruskal() {
    for(int i = 0; i < m; i++) {
        int u = graph[i].second.first;
        int v = graph[i].second.second;
        if (merge(u, v)) {
            // cout << u << " " << v << " " << graph[i].first << endl;
            res |= graph[i].first;
        }
    }
}

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {    
        cin >> n >> m;
        lab.resize(n + 1, -1);
        graph.resize(m);
        res = 0;
        vector < vector < iii > > egde(n);
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            // cout << u << " " << v << " " << w << endl;
            graph[i] = iii(w, ii(u, v));
        }
        sort(graph.begin(),graph.end());
        int cur = 0;
        edge[0].push_back(graph[i]);
        for (int i = 1; i < m; i++) {
            if (graph[i].first != edge[cur][0].first)
                cur++;
            edge[cur].push_back(graph[i]);
        }
        kruskal();
        cout << res << '\n';
    }
}