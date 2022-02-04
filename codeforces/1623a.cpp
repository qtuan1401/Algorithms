#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m, rb, cb, rd, cd;
        cin >> n >> m >> rb >> cb >> rd >> cd;
        int diffRow = rd - rb;
        if (diffRow < 0)
            diffRow = 2 * (n - rb) + rb - rd;
        
        int diffCol = cd - cb;
        if (diffCol < 0)
            diffCol = 2 * (m - cb) + cb - cd;
        cout << min(diffCol, diffRow) << '\n';
    }
    return 0;
}