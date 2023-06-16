#include <bits/stdc++.h>

using namespace std;

vector < vector < int > > lst;
vector < int > sum;
vector < int > isolated; 

void calc(int u, int v, int i) {
    int posU = upper_bound(lst[u].begin(), lst[u].end(), i) - lst[u].begin();
    int posV = upper_bound(lst[v].begin(), lst[v].end(), i) - lst[v].begin();
    posU = lst[u][posU];
    posV = lst[v][posV];
    int pos = posU;
    if (pos > posV) pos = posV;
    if (isolated[u] == -1 || isolated[u] < i) {
        sum[i] += 1;
        sum[pos] -= 1;
        isolated[u] = pos;
    } else {
        int cur = isolated[u];
        if (cur < pos) {
            sum[cur] += 1;
            sum[pos] -= 1;
            isolated[u] = pos;
        }
    }

}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    while (tests--) {
        int n, q;
        cin >> n >> q;
        vector < int > type(q), u(q), v(q);
        lst.resize(n);
        sum.resize(q);
        isolated.resize(n);
        for (int i = 0; i < q; i++) {
            cin >> type[i];
            if (type[i] == 1) {
                cin >> u[i] >> v[i];
                u[i]--; v[i]--;
            } else {
                cin >> u[i];
                u[i]--;
                lst[u[i]].push_back(i);
            }
        }

        for (int i = 0; i < n; i++) {
            lst[i].push_back(q);
            isolated[i] = -1;
        }

        for (int i = 0; i < q; i++) {
            if (type[i] == 1) {
                calc(u[i], v[i], i);
                calc(v[i], u[i], i);
            }
        }

        for (int i = 1; i < q; i++) sum[i] += sum[i - 1];
        for (int i = 0; i < q; i++) cout << n - sum[i] << '\n';
    }
    return 0;
}