#include <bits/stdc++.h>

using namespace std;

vector < int > lab;

int findRoot(int x) {
    if (lab[x] < 0) return x;
    return lab[x] = findRoot(lab[x]);
}

bool merge(int u, int v) {
    if ((u = findRoot(u)) == (v = findRoot(v))) return false;
    if (lab[u] > lab[v]) swap(u, v);
    lab[u] += lab[v];
    lab[v] = u;
    return true;
}

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    int n, d;
    cin >> n >> d;
    lab.resize(n);
    for (int i = 0; i < n; i++)
        lab[i] = -1;
    int cnt = 0;
    while (d--) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        int ans = 0;
        cnt += !merge(x, y);
        for (int i = 0; i < n; i++)
            ans = max(ans, -lab[i]);
        vector < int > temp = lab;
        sort(temp.begin(), temp.end());
        int sum = -temp[0];
        for (int i = 1, j = 0; i < n && j < cnt; i++) {
            if (temp[i] < 0) {
                sum -= temp[i];
                j++;
            }
        }
        ans = max(ans, sum);
        cout << ans - 1 << '\n';
    }
    return 0;
}