#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n, m, tot = 0;
    cin >> n >> m;
    vector < int > cnt(n + 1);
    for(int i = 0; i < m; i++) {
        int x;
        cin >> x;
        tot += (cnt[x] == 0);
        cnt[x]++;
        if (tot == n) {
            cout << "1";
            for(int j = 1; j <= n; j++) {
                cnt[j]--;
                tot -= cnt[j] == 0;
            }
        } else
            cout << "0";
    }
    return 0;
}