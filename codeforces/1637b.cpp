#include <bits/stdc++.h>

using namespace std;

int main() {
    // freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector < int > a(n), mn(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                sum += (j - i + 1);
                for (int k = i; k <= j; k++)
                    sum += (a[k] == 0);
            }
        }

        cout << sum << '\n';
    }
    return 0;
}