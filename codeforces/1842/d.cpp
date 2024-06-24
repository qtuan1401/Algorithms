#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 1;

set < int > s;
vector < vector < int > > adj;
map < pair < int, int >, int > mp;
vector < int > valid;

void dfs(int u) {
    for (auto & p : adj[u]) {
        int v = p;
        if (valid[v] == 0 || s.find(v) != s.end()) continue;
        s.insert(v);
        dfs(v);
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    while (tests--) {
        int n, m;
        cin >> n >> m;
        adj.resize(n);
        for (int i = 0; i < m; i++) {
            int u, v, y;
            cin >> u >> v >> y;
            u--; v--;
            adj[u].push_back(v);
            mp[{u, v}] = y;
            adj[v].push_back(u);
            mp[{v, u}] = y;
        }

        valid.resize(n);
        for (int i = 0; i < n - 1; i++) valid[i] = 1;
        queue < int > qu;
        qu.push(n - 1);

        if (adj[0].size() == 0 || adj[n - 1].size() == 0) {
            cout << "inf\n";
            return 0;
        }

        long long tot = 0;
        vector < pair < string, long long > > ans;

        while (qu.size()) {
            
            int u = qu.front(); qu.pop();
            
            while (adj[u].size()) {
                int v = adj[u].back();
                if (!valid[v]) {
                    adj[u].pop_back();
                    continue;
                }
                s.clear();
                s.insert(v);
                dfs(v);

                string game = "";
                int mn = INF;
                for (int v = 0; v < n; v++) {
                    if (s.find(v) != s.end()) {
                        game += "1";

                        for (int & k : adj[v]) {
                            if (!valid[k]) mn = min(mn, mp[{v, k}]);
                        }
                    }
                    else {
                        bool one = true;
                        for (int & k : adj[v]) {
                            if (!valid[k]) one = false;
                        }
                        if (one && valid[v]) game += "1";
                        else game += "0";
                    }
                }

                vector < int > temp;
                for (int v = 0; v < n; v++) {
                    if (s.find(v) != s.end()) {
                        for (int & k : adj[v]) {
                            if (!valid[k]) 
                            mp[{v, k}] -= mn;
                            if (mp[{v, k}] == 0) temp.push_back(v);
                        }
                    }
                }

                for (auto & e : temp) {
                    valid[e] = 0;
                    qu.push(e);
                }
                ans.push_back({game, mn});
                tot += mn;
                if (!valid[0]) break;
                // for (int i = 0; i < n; i++) cout << valid[i] << " ";
                // cout << endl;
            }
            

            if (!valid[0]) break;
        }

        for (int i = 0; i < n; i++) {
            if (valid[0] && valid[i]) {
                cout << "inf\n";
                return 0;
            }
        }

        cout << tot << " " << ans.size() << '\n';
        for (auto & p : ans) cout << p.first << " " << p.second << '\n';
    }
    return 0;
}