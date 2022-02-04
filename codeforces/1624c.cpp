#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector < int > a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            while (a[i] > n)
                a[i] /= 2;
        }
        vector < bool > marked(n + 1, false);
        for (int i = 0; i < n; i++) {
            while (marked[a[i]] == true && a[i] > 0) {
                a[i] /= 2;
            }
            marked[a[i]] = true;
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++)
            cnt += marked[i];
        cout << (cnt == n ? "YES" : "NO") << '\n';
    }
    return 0;
}