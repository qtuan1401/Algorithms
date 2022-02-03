#include <bits/stdc++.h>

using namespace std;

const int MXN = 1e5 + 10;

long long sum[2];
long long a[MXN];

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        if (i < n / 2)
            sum[0] += a[i];
        else
            sum[1] += a[i];
    }

    cout << sum[0] * sum[0] + sum[1] * sum[1];
    return 0;
}