#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k; 
        vector < int > a(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];

        while (true) {
            bool found = false;
            for (int i = 0; i < n; i++)
                if (k >= a[i]) {
                    k += b[i];
                    a[i] = 1e9;
                    found = true;
                }
            if (!found) break;
        }
        cout << k << '\n';
    }
    
    return 0;
}