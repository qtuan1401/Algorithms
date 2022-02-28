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
        set < int > s;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            s.insert(x);
        }

        int mx = s.size();
        for (int i = 0; i < n; i++) 
            cout << max(mx, i + 1) << " ";
        cout << '\n';
    }
    return 0;
}