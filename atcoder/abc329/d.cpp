#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair < int, int > pii;



int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    while (tests--) {
        int n, m;
        cin >> n >> m;

        priority_queue < pii > heap;
        vector < int > cnt(n);
        for (int i = 0; i < m; i++) {
            int x;
            cin >> x;
            x--;
            cnt[x]++;
            heap.push(pii(cnt[x], -x));

            cout << -heap.top().second + 1 << '\n';
        }
    }
    return 0;
}