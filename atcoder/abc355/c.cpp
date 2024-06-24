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

bool isSameDiagnol(int x, int y, int u, int v) {
    return abs(x - u) == abs(y - v);
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    while (tests--) {
        int n, t;
        cin >> n >> t;
        vector < vector < int > > info(n * n + 1);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int id = n * (i - 1) + j;
                info[id].push_back(i);
                info[id].push_back(n + j);
                if (isSameDiagnol(1, 1, i, j)) info[id].push_back(2 * n + 1);
                if (isSameDiagnol(1, n, i, j)) info[id].push_back(2 * n + 2);

            }
        }

        vector < int > tot(2 * n + 3);
        for (int turn = 1; turn <= t; turn++) {
            int x;
            cin >> x;
            bool bingo = false;
            for (auto & e : info[x]) {
                tot[e]++;
                if (tot[e] == n) bingo = true;
            }
            if (bingo) {
                cout << turn << '\n';
                return 0;
            }
        }
        cout << "-1\n";
    }
    return 0;
}