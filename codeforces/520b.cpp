#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int cnt = 0, n, m;
    cin >> n >> m;
    while (n < m) {
        if (m & 1)
            m++;
        else
            m /= 2;
        cnt++;
    }
    cout << cnt + n - m;
    return 0;
}