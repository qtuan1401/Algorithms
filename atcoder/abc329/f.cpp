#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair < int, int > pii;

vector < set < int > > num;
vector < int > lab;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    while (tests--) {
        int n, q;
        cin >> n >> q;

        num.resize(n);
        vector < int > pos(n);

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            num[i].insert(x);
            pos[i] = i;
        }
        while (q--) {
            int a, b;
            cin >> a >> b;
            a--; b--;

            
            if (num[pos[a]].size() > num[pos[b]].size()) {
                swap(pos[a], pos[b]);
            }

            for (auto & x : num[pos[a]]) {
                num[pos[b]].insert(x);
            }

            num[pos[a]].clear();

            cout << num[pos[b]].size() << '\n';
        }
    }
    return 0;
}