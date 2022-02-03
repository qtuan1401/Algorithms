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
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a.begin(), a.end());
        int sum = 0;
        for (int i = n - 2; i >= 0; i--) {
            sum += a[i];
        }
        cout << fixed << setprecision(10);
        cout << (double)sum / (n - 1) + (double)a[n - 1] << '\n';
    }
    return 0;
}