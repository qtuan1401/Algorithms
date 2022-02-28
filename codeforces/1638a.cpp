#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector < int > a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i]--;
        }

        int l = 0, r = 0;
        for (int i = 0; i < n; i++)
            if (a[i] != i) {
                l = i;
                break;
            }
        
        for (int i = 0; i < n; i++)
            if (a[i] == l) {
                r = i;
                break;
            }

        for (int i = l; i < l + (r - l + 1) / 2; i++)
            swap(a[i], a[r - i + l]);
        for (int i = 0; i < n; i++)
            cout << a[i] + 1 << " ";
        cout << '\n';
    }
    return 0;
}