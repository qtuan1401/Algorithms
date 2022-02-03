#include <bits/stdc++.h>


using namespace std;

int n;
vector < int > adj[10005];

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i < n; i++) {
        int v;
        cin >> v;
        adj[v].push_back(i + 1); 
        //cout << v << " " << i + 1 << endl;
    }

    for(int i = 1; i <= n; i++) {
        //cout << i << " " << adj[i].size() << endl;
        if (adj[i].size() == 0)
            continue;
        int cnt = 0;
        for(int j = 0; j < adj[i].size(); j++)
            cnt += (adj[adj[i][j]].size() == 0);
        //cout << i << " " << cnt << endl;
        if (cnt < 3) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
    return 0;
}