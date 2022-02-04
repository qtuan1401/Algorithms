#include <bits/stdc++.h>

using namespace std;

typedef pair < int, int > PII;
typedef pair < PII, PII > PIIII;
typedef pair < long long, int > PLLI;

vector < PIIII > edge, origin;
vector < int > lab, pos;
vector < PLLI > ans;
int n, m;

bool check(int x) {
    vector < PIIII > temp(m);
    temp = origin;
    for (int i = 0; i < m; i++) 
        temp[i].first.first = abs(x - origin[i].first.first);
    sort(temp.begin(), temp.end());
    for (int i = 0; i < m; i++)
        if (edge[i].first.second != temp[i].first.second)
            return true;
    return false;
}

int bs(int l, int r, int x) {
    int ans = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        // cout << x << " " << mid << " " << check(x + mid) << endl;
        if (check(x + mid)) {
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    return ans;
}

int root(int x) {
    if (lab[x] < 0) return x;
    return lab[x] = root(lab[x]);
}

bool merge(int u, int v) { 
    if ((u = root(u)) == (v = root(v))) return false;
    if (lab[u] > lab[v]) swap(u, v);
    lab[u] += lab[v];
    lab[v] = u;
    return true;
}

PLLI kruskal(int x) {
    lab.resize(n);
    for (int i = 0; i < n; i++)
        lab[i] = -1;
    PLLI sum = {0ll, 0ll};
    for (int i = 0; i < m; i++) {
        int u = edge[i].second.first;
        int v = edge[i].second.second;
        if (merge(u, v)) {
            sum.first += edge[i].first.first;
            sum.second += origin[edge[i].first.second].first.first <= x;
        }
    }
    return sum;
}

int bs1(int l, int r, int x) {
    int ans = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (pos[mid] <= x) {
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    return ans;
}

long long calc(int x) {
    int p = bs1(0, pos.size() - 1, x);
    return ans[p].first + (x - pos[p]) * ans[p].second - (x - pos[p]) * (n - 1 - ans[p].second);
}

void push(int x) {
    edge = origin;
    for (int i = 0; i < m; i++)
        edge[i].first.first = abs(x - origin[i].first.first);
    sort(edge.begin(), edge.end());
    for (int i = 0; i < m; i++)
        cout << edge[i].first.first << " ";
    cout << endl;
    pos.push_back(x);
    ans.push_back(kruskal(x));
}

int main() {
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    edge.resize(m); origin.resize(m);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        origin[i] = {{w, i}, {u, v}};
    }
    edge = origin;
    sort(edge.begin(), edge.end());
    int mn = edge[0].first.first, mx = edge.back().first.first;
    push(0);
    push(mn);
    int x = mn;
    while (x < mx) {
        int p = bs(1, 1e9, x);
        if (p == 0) break;
        x += p;
        push(x);
    }
    push(max(x, mx + 1));
    for (int i = 0; i < pos.size(); i++)
        cout << i << " " << pos[i] << " " << ans[i].first << endl;
    int p, k, a, b, c, q;
    long long res = 0;
    cin >> p >> k >> a >> b >> c;
    for (int i = 0; i < p; i++) {
        int x;
        cin >> x;
        if (i + 1 == p)
            q = x;
        res ^= calc(x);
    }

    for (int i = p; i < k; i++) {
        q = (1ll * q * a + b) % c;
        cout << q << " ";
        res ^= calc(q);
    }

    cout << res << '\n';
    return 0;
}