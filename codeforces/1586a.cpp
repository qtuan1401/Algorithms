#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int sum = 0;
        vector < int > a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }
        bool isComposite = false;
        for (int i = 2; i * i <= sum; i++)
            if (sum % i == 0) isComposite = true;
        int ignore = -1;
        if (!isComposite) {
            for (int i = 0; i < n; i++)
                if (a[i] & 1) ignore = i;
        }

        cout << n - (ignore >= 0) << '\n';
        for (int i = 0; i < n; i++)
            if (i != ignore) cout << i + 1 << " ";
        cout << '\n';
    }
    return 0;
}