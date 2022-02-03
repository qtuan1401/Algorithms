#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n, pos, l, r;
    cin >> n >> pos >> l >> r;
    int timeL = 0, timeR = 0;
    if (pos >= l && pos <= r) {
        if (l == 1 && r == n) {
            cout << 0;
        } else if (l == 1) {
            cout << r - pos + 1;
        } else if (r == n)
            cout << pos - l + 1;
        else 
            cout << min(pos - l + 1, r - pos + 1) + (r - l + 1);
    } else if (pos < l) {
        cout << (l - pos + 1) + (r < n ? r - l + 1 : 0);
    } else 
        cout << (pos - r + 1) + (l > 1 ? r - l + 1 : 0);
    return 0;
}