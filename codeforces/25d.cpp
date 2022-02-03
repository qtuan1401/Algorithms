#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e3 + 10;

vector < pair < int, int > > removeList;
int n;
int root[MAXN];

int getRoot(int v) {
    if (root[v] < 0)
        return v;
    return root[v] = getRoot(root[v]);
}

bool merge(int u, int v) {
    if ((u = getRoot(u)) == (v = getRoot(v)))
        return false;
    //cout << u << " * " << v << endl;
    if (root[u] > root[v])
        swap(u, v);
    root[u] += root[v];
    root[v] = u;
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        root[i] = -1;
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        if (!merge(u, v)) {
            //cout << u << " .. " << v << endl;
            removeList.push_back(make_pair(u, v));
        }
    }
    vector < int > v;
    for(int i = 1; i <= n; i++)
        v.push_back(getRoot(i));
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    cout << v.size() - 1 << '\n';
    for(int i = 1; i < v.size(); i++) 
        cout << removeList[i - 1].first << " " << removeList[i - 1].second << " " << v[i - 1] << " "  << v[i] << '\n';
    return 0;
}