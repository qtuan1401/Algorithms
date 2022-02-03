#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        int p, q;
        cin >> p >> q;
        cnt += (q - p >= 2);
    }
    cout << cnt;
    return 0;
}