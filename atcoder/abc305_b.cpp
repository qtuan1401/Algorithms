#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    while (tests--) {
        char p, q;
        cin >> p >> q;
        int l = p - 'A', r = q - 'A';
        if (l > r) swap(l, r);

        vector < int > sum(7);
        sum[1] = 3;
        sum[2] = 1;
        sum[3] = 4;
        sum[4] = 1;
        sum[5] = 5;
        sum[6] = 9;
        for (int i = 1; i < 7; i++)
            sum[i] += sum[i - 1];
        cout << sum[r] - sum[l];
    }
    return 0;
}