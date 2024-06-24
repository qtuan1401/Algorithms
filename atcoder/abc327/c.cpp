#include <bits/stdc++.h>

#define vall(a) (a.begin(), a.end())

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    while (tests--) {
        int n = 9, m = 9;

        vector < vector < int > > a(n, vector < int > (m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> a[i][j];
        }

        for (int i = 0; i < n; i++) {
            vector < int > cnt(10, 0);
            for (int j = 0; j < m; j++) {
                cnt[a[i][j]]++;
                
                if (cnt[a[i][j]] > 1) {
                    cout << "No\n";
                    exit(0);
                }
            }
        }

        for (int j = 0; j < m; j++) {
            vector < int > cnt(10, 0);
            for (int i = 0; i < n; i++) {
                cnt[a[i][j]]++;
                
                if (cnt[a[i][j]] > 1) {
                    cout << "No\n";
                    exit(0);
                }
            }
        }

        for (int i = 0; i < n; i += 3) {
            for (int j = 0; j < m; j += 3) {
                vector < int > cnt(10, 0);
                for (int ii = i; ii < i + 3; ii++) {
                    for (int jj = j; jj < j + 3; jj++) {
                        cnt[a[ii][jj]]++;

                        if (cnt[a[ii][jj]] > 1) {
                            cout << "No\n";
                            exit(0);
                        }
                    }
                }
            }
        }

        cout << "Yes\n";
    }
    return 0;
}