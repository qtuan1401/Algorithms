#include <bits/stdc++.h>

using namespace std;

typedef pair < int, int > PII;

int n;
vector < int > a, b, ans;

void bfs(int s) {
    queue < int > q;
    q.push(s);
    vector < bool > marked(n, false);
    marked[s] = true;
    vector < PII > trc(n);
    int r = n - 1;
    while (q.size()) {
        int u = q.front(); q.pop();
        int l = u - a[u];
        // cout << u << " " << l << " " << r << endl;
        if (l == -1) {
            ans.push_back(0);
            // cout << u << endl;
            while (u != n - 1) {
                ans.push_back(trc[u].second + 1);
                u = trc[u].first;
            }
            break;
        }
        for (int i = l; i < r; i++) {
            int v = i + b[i];
            if (marked[v]) continue;
            trc[v] = {u, i};
            marked[v] = true;
            q.push(v);
        }
        r = min(r, l);
    }
}

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n;
    a.resize(n); b.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    bfs(n - 1);

    if (!ans.size()) cout << "-1\n";
    else {
        reverse(ans.begin(), ans.end());
        cout << ans.size() << '\n';
        for (int & val : ans) cout << val << " ";
        cout << '\n';
    }
    return 0;
}