#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        long long res = 0, temp = 1;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x == 1) res++;
            if (x == 0) temp *= 2;
        }
        
        cout << res * temp << '\n';
    }
    return 0;
}