#include <bits/stdc++.h>

using namespace std;

int root[55];

int findRoot(int x) {
    if (root[x] == x)
        return x;
    return root[x] = findRoot(root[x]);
}

int main() {
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    long long res = 1;
    for(int i = 1; i <= n; i++)
        root[i] = i;
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x = findRoot(x);
        y = findRoot(y);
        if (x != y) {
            res *= 2;
            root[y] = x;
        }
    }
    cout << res;
    return 0;
}