#include <bits/stdc++.h>

using namespace std;

const int MXN = 1e5 + 10;

int n, m;
int sum[35][MXN], l[MXN], r[MXN], q[MXN];

inline int getBit(int x, int i) {
    return ((x >> i) & 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> l[i] >> r[i] >> q[i];
    }
    for(int bit = 0; bit < 30; bit++) {
        for(int i = 0; i < m; i++)
            if (getBit(q[i], bit))
                sum[bit][l[i]]++, sum[bit][r[i] + 1]--;
        for(int i = 1; i <= n; i++)
            sum[bit][i] += sum[bit][i - 1];
        for(int i = 1; i <= n; i++) {
            if (sum[bit][i] > 0)
                sum[bit][i] = 1;
            sum[bit][i] += sum[bit][i - 1];
        }
        for(int i = 0; i < m; i++) {
            if (getBit(q[i], bit)) {
                if (sum[bit][r[i]] - sum[bit][l[i] - 1] != (r[i] - l[i] + 1)) {
                    cout << "NO";
                    return 0;
                }
            } else {
                if (sum[bit][r[i]] - sum[bit][l[i] - 1] == (r[i] - l[i] + 1)) {
                    cout << "NO";
                    return 0;
                }
            }
        }
    }
    cout << "YES\n";
    for(int i = 1; i <= n; i++) {
        int val = 0;
        for(int j = 0; j < 30; j++)
            if (sum[j][i] - sum[j][i - 1] == 1)
                val ^= (1 << j);
        cout << val << " ";
    }
    return 0;
}