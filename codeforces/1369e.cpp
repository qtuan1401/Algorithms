#include <bits/stdc++.h>

using namespace std;

typedef pair < int, int > II;

const int MXN = 2e5 + 10;

priority_queue < II > heap;
int n, m;
int w[MXN], s[MXN], x[MXN], y[MXN];
bool marked[MXN], vis[MXN];
vector < int > food[MXN], res;

int main() {
    //freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    for (int i = 0; i < m; i++) {
        cin >> x[i] >> y[i];
        s[x[i]]++; s[y[i]]++;
        food[x[i]].push_back(i);
        food[y[i]].push_back(i);
    }

    for (int i = 1; i <= n; i++) {
        if (s[i])
            heap.push(II(min(0, w[i] - s[i]), i));
        else
            marked[i] = 1;
    }

    while (heap.size()) {
        II cur = heap.top(); heap.pop();
        int u = cur.second;
        //cout << u << " " << cur.first << " " << w[u] - s[u] << " " << w[u] << " " << s[u endl;
        if (cur.first != min(0, w[u] - s[u]))
            continue;
        if (cur.first < 0) {
            cout << "DEAD";
            return 0;
        }

        vector < int > t;
        for (int i = 0; i < food[u].size(); i++) {
            int v = food[u][i];
            if (vis[v])
                continue;
            res.push_back(v);
            if (x[v] == u)
                swap(x[v], y[v]);
            if (!marked[x[v]])
                t.push_back(x[v]);
            vis[v] = 1;
        }

        sort(t.begin(), t.end());
        for (int i = 0; i < t.size(); i++) {
            s[t[i]]--;
            if (i == t.size() - 1 || t[i + 1] != t[i]) {
                if (s[t[i]]) {
                    if (min(0, w[t[i]] - s[t[i]]) == 0)
                        marked[t[i]] = 1;
                    heap.push(II(min(0, w[t[i]] - s[t[i]]), t[i]));
                }
            }
        }
    }
    
    cout << "ALIVE\n";
    reverse(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++)
        cout << res[i] + 1 << " ";
    return 0;
}