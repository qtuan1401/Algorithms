#include <bits/stdc++.h>

using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    while (tests--) {
        int n = 10, m = 100;
        vector < vector < int > > pos(n + 1);
        for (int i = 0; i <= m; i++) {
            cout << i << ": ";
            set < int > s;
            for (int j = n; j >= 1; j--) {
                cout << i % j << " ";
                s.insert(i % j);
                pos[j].push_back(i % j);
            }
            cout << " | " << s.size() << endl;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                cout << i << " " << j << endl;
                for (int k = 0; k < pos[i].size(); k++)
                    if (pos[i][k] == pos[j][k]) cout << k << " ";
                cout << endl;
            }
        }
    }
    return 0;
}