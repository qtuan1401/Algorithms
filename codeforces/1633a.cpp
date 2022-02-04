#include <bits/stdc++.h>

using namespace std;

int calc(int a, int b) {
    int cnt = 0;
    while (b > 0 || a > 0) {
        if (b > 0 && a == 0) return 4;
        if (a > 0 && b == 0) return 4;
        cnt += (a % 10 != b % 10);
        a /= 10;
        b /= 10;
    }
    return cnt;
}

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int res = n, mn = 4;
        for (int i = 1; i <= 999; i++)
            if (i % 7 == 0) {
                if (mn > calc(n, i)) {
                    mn = calc(n, i);
                    res = i;
                }
            }
        cout << res << '\n';
    }
    return 0;
}