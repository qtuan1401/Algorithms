#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    long long l, w;
    cin >> n >> l >> w;
    long long res = 0, pos = 0;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        if (x <= pos)
            pos = max(pos, x + w);
        else {
            long long diff = x - pos;
            res += diff / w + (diff % w > 0);
            pos = x + w;
        }
    }
    if (pos < l) {
        long long diff = l - pos;
        res += diff / w + (diff % w > 0);
    }
    cout << res;
    return 0;
}