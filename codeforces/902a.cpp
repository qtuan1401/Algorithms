#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    int r = 0;
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (r >= a) {
            r = max(r, b);
        } else
            break;
        if (r >= m) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}