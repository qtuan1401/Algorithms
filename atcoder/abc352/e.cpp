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

vector < int > lab;

int getRoot(int x) {
    if (lab[x] < 0) return x;
    return lab[x] = getRoot(lab[x]);
}

void merge(int u, int v) {
    u = getRoot(u);
    v = getRoot(v);
    if (u == v) {
        return ;
    }

    if (lab[u] > lab[v]) swap(u, v);
    lab[u] += lab[v];
    lab[v] = u;
    return ;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    while (tests--) {
        int n, m;
        cin >> n >> m;
        vector < vector < int > > vet(m);
        vector < pii > w(m);
        lab.resize(n);
        for (int i = 0; i < n; i++) lab[i] = -1;
        for (int i = 0; i < m; i++) {
            int k;
            cin >> k >> w[i].first;
            w[i].second = i;
            vet[i].resize(k);
            for (int j = 0; j < k; j++) {
                cin >> vet[i][j];
                vet[i][j]--;
            }
        }

        sort(w.begin(), w.end());

        int cnt = 0;
        long long sum = 0;
        for (int i = 0; i < m; i++) {
            int id = w[i].second;
            vector < int > nodes;
            for (auto & e : vet[id]) {
                nodes.push_back(getRoot(e));
            }

            sort(nodes.begin(), nodes.end());
            nodes.erase(unique(nodes.begin(), nodes.end()), nodes.end());

            for (int j = 1; j < nodes.size(); j++) {
                merge(nodes[j - 1], nodes[j]);
                sum += w[i].first;
                cnt++;
                if (cnt == n - 1) {
                    cout << sum << '\n';
                    return 0;
                }
            }
        }

        cout << -1 << '\n';
    }
    return 0;
}