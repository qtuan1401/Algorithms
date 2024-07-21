#include <bits/stdc++.h>

using namespace std;

template < class T >
void resetVec(vector < T > & a, int sz, T val) {
    a.clear();
    a.resize(sz, val);
}

typedef long double ld;
typedef long long ll;
typedef pair < int, int > pii;
typedef pair < int, pii > piii;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int n, m, y;
vector < vector < int > > a;

const int INF = 1e6;

void prim() {
    vector < vector < int > > f(n, vector < int > (m, INF));
    priority_queue < piii, vector < piii >, greater < piii > > heap;
    for (int i = 0; i < n; i++) {
        f[i][0] = a[i][0];
        f[i][m - 1] = a[i][m - 1];
        heap.push({f[i][0], {i, 0}});
        heap.push({f[i][m - 1], {i, m - 1}});
    }

    for (int i = 0; i < m; i++) {
        f[0][i] = a[0][i];
        f[n - 1][i] = a[n - 1][i];

        heap.push({f[0][i], {0, i}});
        heap.push({f[n - 1][i], {n - 1, i}});
    }

    while (heap.size()) {
        piii cur = heap.top(); heap.pop();
        int val = cur.first;
        int u = cur.second.first;
        int v = cur.second.second;
        if (val > f[u][v]) continue;
        for (int dir = 0; dir < 4; dir++) {
            int nu = u + dx[dir];
            int nv = v + dy[dir];
            if (nu < 0 || nu >= n || nv < 0 || nv >= m) continue;
            int w = max(a[nu][nv], val);
            if (f[nu][nv] > w) {
                f[nu][nv] = w;
                heap.push({f[nu][nv], {nu, nv}});
            }
        }
    }

    vector < int > cnt(y, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (f[i][j] > y) continue;
            cnt[f[i][j] - 1]++;
        }
    }
    int sum = 0;
    for (int i = 0; i < y; i++) {
        sum += cnt[i];
        cout << n * m - sum << '\n';
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;

    while (tests--) {
        cin >> n >> m >> y;
        a.resize(n, vector < int > (m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) cin >> a[i][j];
        }
        prim();
    }
    return 0;
}