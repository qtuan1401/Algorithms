#include <bits/stdc++.h>

using namespace std;

vector < int > a;
vector < vector < int > > adj;
vector < bool > marked, res;

bool dfs(int u) {
    if (marked[u] == true)
        return res[u];
    marked[u] = true;
    if (adj[u].size() == 0)
        return res[u] = false;

    bool temp = false;
    for (int i = 0; i < adj[u].size(); i++) {
        temp |= !dfs(adj[u][i]);
    }
    
    return res[u] = temp;
}

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    a.resize(n);
    adj.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j += a[i])
            if (a[j] > a[i]) 
                adj[i].push_back(j);
        for (int j = i; j >= 0; j -= a[i])
            if (a[j] > a[i])
                adj[i].push_back(j);
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < adj[i].size(); j++)
    //         cout << adj[i][j] << " ";
    //     cout << endl;
    // }

    marked.resize(n); res.resize(n);
    for (int i = 0; i < n; i++)
        marked[i] = res[i] = false;
    for (int i = 0; i < n; i++) {
        if (marked[i] == false) {
            dfs(i);
        }
    }
    for (int i = 0; i < n; i++)
        if (res[i] == false)
            cout << "B";
        else
            cout << "A";
    return 0;
}