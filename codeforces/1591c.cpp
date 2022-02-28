#include <bits/stdc++.h>

using namespace std;

vector < vector < int > > val(2);

long long calc(int id, int k) {
    long long res = 0;
    for (int i = (int)val[id].size() - 1; i >= 0; i -= k)
        res += val[id][i] * 2;
    id = 1 - id;
    for (int i = (int)val[id].size() - 1; i >= 0; i -= k)
        res += val[id][i] * 2;
    if (val[id].size()) res -= val[id].back();
    return res;
}

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        val[0].clear(); val[1].clear();
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            val[x < 0].push_back((x < 0) ? -x : x);
        }
        for (int i = 0; i < 2; i++)
            sort(val[i].begin(), val[i].end());

        cout << min(calc(0, k), calc(1, k)) << '\n';
    }
    return 0;
}