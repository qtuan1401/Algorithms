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

vector < vector < int > > ans;
vector < int > pp;
void recur(int n, int u, int v) {
    if (n == 0) {
        ans[u][v] = 1;
        return;
    }
    int cnt = 0;
    // cout << n << " " << u << " " << v << endl;
    for (int i = u; i < u + pp[n]; i += pp[n - 1]) {
        for (int j = v; j < v + pp[n]; j += pp[n - 1]) { 
            // cout << i << " " << j << " " << n << " " << cnt << endl;
            if (cnt != 4) {
                recur(n - 1, i, j);
            } else {
                for (int ii = i; ii < i + pp[n - 1]; ii++) {
                    for (int jj = j; jj < j + pp[n - 1]; jj++) {
                        ans[ii][jj] = 0;
                    }
                }
            }
            cnt++;
        }
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    while (tests--) {
        int n;
        cin >> n;
        pp.resize(n + 1);
        pp[0] = 1;
        for (int i = 1; i <= n; i++) pp[i] = pp[i - 1] * 3;
        resetVec(ans, pp[n], vector < int > (pp[n], 0));
        recur(n, 0, 0);

        for (int i = 0; i < pp[n]; i++) {
            for (int j = 0; j < pp[n]; j++) {
                if (ans[i][j] == 0) cout << ".";
                else cout << "#";
            }
            cout << '\n';
        }
    }
    return 0;
}