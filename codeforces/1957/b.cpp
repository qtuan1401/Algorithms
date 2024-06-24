#include <bits/stdc++.h>

using namespace std;

template < class T >
void resetVec(vector < T > & a, int sz, T val) {
    a.clear();
    a.resize(sz, val);
}

typedef long double ld;
typedef long long ll;
typedef pair < int, int > pii;

int getBit(int x, int i) {
    return (x >> i) & 1;
}

int flipBit(int x, int i) {
    return x ^ (1 << i);
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests;
    cin >> tests;
    while (tests--) {
        int n, k;
        cin >> n >> k;

        vector < int > ans(n, 0);
        ans[0] = k;

        if (n == 1) {
            cout << ans[0] << '\n';
            continue;
        }

        int flag = 0;
        for (int i = 30; i >= 0; i--) {
            if (flag == 1) {
                if (getBit(ans[0], i) == 0) ans[0] = flipBit(ans[0], i);
            } else if (getBit(ans[0], i) == 1 && flag == 0) {
                ans[0] = flipBit(ans[0], i);
                flag = 1;
            }
        }

        ans[1] = k - ans[0];
        for (int i = 0; i < n; i++) cout << ans[i] << " ";
        // int temp = ans[0] | ans[1];
        // int cnt = 0;
        // for (int i = 0; i < 30; i++) cnt += getBit(temp, i);
        // cout << cnt;
        cout << '\n';
    }
    return 0;
}