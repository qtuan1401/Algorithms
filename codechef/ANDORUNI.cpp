#include <bits/stdc++.h>

using namespace std;

int getBit(int x, int i) {
    return (x >> i) & 1;
}

int flipBit(int x, int i) {
    return x ^ (1 << i);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector < int > cnt(31, 0);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            for (int j = 0; j < 31; j++)
                cnt[j] += getBit(x, j);
        }
        int res = 0;
        for (int i = 0; i < 31; i++)
            if (cnt[i] > 1)
                res = flipBit(res, i);
        cout << res << '\n';
    }
    return 0;
}