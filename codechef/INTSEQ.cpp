#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int k;
        cin >> k;
        if (k % 2 == 1) cout << "0\n";
        else cout << (int)log2(k) << '\n';
    }
    return 0;
}