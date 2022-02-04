#include <bits/stdc++.h>

using namespace std;

int getBit(int x, int i) {
    return (x >> i) & 1;
}

int flipBit(int x, int i) {
    return (1 << i) ^ x;
}

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, l;
        cin >> n >> l;
        vector < vector < int > > cnt(l, vector < int > (2, 0));
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            for (int j = 0; j < l; j++)
                cnt[j][getBit(x, j)]++;
        }
        int ans = 0;
        for (int j = 0; j < l; j++)
            if (cnt[j][1] > cnt[j][0])
                ans = flipBit(ans, j);
        cout << ans << '\n';
    }

    return 0;
}