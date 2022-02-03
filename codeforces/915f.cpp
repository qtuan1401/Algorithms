#include <bits/stdc++.h>

using namespace std;

typedef pair < int, int > II;
typedef pair < int, II > III;

const int MXN = 1e6 + 10;

III graph[MXN];
int lab[MXN], a[MXN], u[MXN], v[MXN];
int n;

int findRoot(int v) {
    if (lab[v] < 0)
        return v;
    return lab[v] = findRoot(lab[v]);
}

void merge(int u, int v, int w, long long & res) {
    if ((u = findRoot(u)) == (v = findRoot(v))) 
        return ;
    if (lab[u] > lab[v]) 
        swap(u, v);
    res += 1ll * abs(lab[u]) * abs(lab[v]) * w;
    lab[u] += lab[v];
    lab[v] = u; 
}

long long calc(int sign) {
    long long res = 0;
    for(int i = 1; i <= n; i++)
        lab[i] = -1;
    for(int i = 0; i < n - 1; i++) 
        graph[i] = III(max(a[u[i]] * sign, a[v[i]] * sign), II(u[i], v[i]));
    sort(graph, graph + n - 1);
    for(int i = 0; i < n - 1; i++) {
        int u = graph[i].second.first;
        int v = graph[i].second.second;
        merge(u, v, graph[i].first, res);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 0; i < n - 1; i++)
        cin >> u[i] >> v[i];
    cout << calc(1) + calc(-1);    
    return 0;
}