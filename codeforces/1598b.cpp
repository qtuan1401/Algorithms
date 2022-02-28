#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector < vector < int > > a(n, vector < int > (5));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 5; j++)
                cin >> a[i][j];
        }

        bool ok = false;
        for (int j = 0; j < 5; j++) {
            for (int k = j + 1; k < 5; k++) {
                int cnt = 0;
                vector < int > marked(n, false);
                for (int i = 0; i < n && cnt < n / 2; i++) {
                    if (a[i][j] == 1 && a[i][k] == 0) {
                        marked[i] = true;
                        cnt++;
                    }
                }

                for (int i = 0; i < n && cnt < n / 2; i++) {
                    if (a[i][j] == 1 && a[i][k] == 1) {
                        marked[i] = true;
                        cnt++;
                    }
                }

                if (cnt < n / 2) continue;
                cnt = 0;
                for (int i = 0; i < n; i++)
                    if (a[i][k] == 1 && !marked[i]) cnt++;
                if (cnt == n / 2) {
                    ok = true;
                    break;
                }
            }
        }

        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}