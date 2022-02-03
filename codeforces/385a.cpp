#include <bits/stdc++.h>

using namespace std;
 
int main() {
    ios_base::sync_with_stdio(0);
    int n, c;
    int pre = 0, mx = 0;
    cin >> n >> c;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mx = max(mx, (pre - x - c));
        pre = x;
    }
    cout << mx;
    return 0;
}