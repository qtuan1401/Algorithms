#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e3 + 10;

typedef pair < int, int > II;
typedef pair < long long, II > III;

III mst[MAXN * MAXN];
vector < II > edges;
vector < int > cities;
int lab[MAXN], k[MAXN], c[MAXN], x[MAXN], y[MAXN];
long long res;
int n, m;

int getRoot(int x) {
    if (lab[x] < 0)
        return x;
    return lab[x] = getRoot(lab[x]);
}

bool merge(int u, int v) {
    if ((u = getRoot(u)) == (v = getRoot(v))) 
        return false;
    if (lab[u] > lab[v])
        swap(u, v);
    lab[u] += lab[v];
    lab[v] = u;
    return true;
}

void kruskal() {
    for(int i = 0; i < m; i++) {
        int u = mst[i].second.first;
        int v = mst[i].second.second;
        if (merge(u, v)) {
            res += mst[i].first;
            if (u == 0)
                cities.push_back(v);
            else if (v == 0)
                cities.push_back(u);
            else edges.push_back(II(u, v));
        }
    }
}

long long calc(int i, int j) {
    if (i == 0)
        return c[j];
    return 1ll * (k[i] + k[j]) * (abs(x[i] - x[j]) + abs(y[i] - y[j]));
} 

int main() {
    //freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n;
    x[0] = 0; y[0] = 0;
    for(int i = 1; i <= n; i++) 
        cin >> x[i] >> y[i];
    for(int i = 1; i <= n; i++)
        cin >> c[i];
    for(int i = 1; i <= n; i++)
        cin >> k[i];
    for(int i = 0; i <= n; i++)
        lab[i] = -1;
    for(int i = 0; i <= n; i++)
        for(int j = i + 1; j <= n; j++)
            mst[m++] = III(calc(i, j), II(i, j));
    sort(mst, mst + m);
    kruskal();

    cout << res << '\n';
    cout << cities.size() << '\n';
    for(int i = 0; i < cities.size(); i++)
        cout << cities[i] << " ";
    cout << '\n' << edges.size() << '\n';
    for(int i = 0; i < edges.size(); i++)
        cout << edges[i].first << " " << edges[i].second << '\n';
    return 0;
}