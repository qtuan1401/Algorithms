#include <bits/stdc++.h>

using namespace std;

vector < int > a, b;

void calc(int x, int y, int i, int j) {
    int lcm = x * y / __gcd(x, y);
    b[i] = lcm / x;
    b[j] = lcm / y;
    // cout << i << " " << j << " " << a[i] << " " << a[j] << endl;
    if (a[i] > 0) b[i] = -b[i];
    if (a[j] < 0) b[j] = -b[j];
}

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        a.resize(n); b.resize(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        if (n % 2 == 0) {
            for (int i = 0; i < n; i += 2)
                calc(abs(a[i]), abs(a[i + 1]), i, i + 1);
        } else {
            for (int i = 0; i < n; i++)
                for (int j = i + 1; j < n; j++)
                    if (a[i] + a[j] != 0) {
                        int k = 3 - i - j;
                        int sum = a[i] + a[j];
                        int lcm = abs(sum) * abs(a[k]) / __gcd(abs(sum), abs(a[k]));
                        // cout << lcm << " " << sum << endl;
                        b[i] = b[j] = lcm / abs(sum);
                        b[k] = lcm / abs(a[k]);
                        if (sum > 0) b[j] = b[i] = -b[i];
                        if (a[n - 1] < 0) b[k] = -b[k];
                    }
            for (int i = 3; i < n; i += 2)
                calc(abs(a[i]), abs(a[i + 1]), i, i + 1);
        }

        for (int i = 0; i < n; i++)
            cout << b[i] << " ";
        // cout << endl;
        // long long sum = 0;
        // for (int i = 0; i < n; i++) {
        //     sum += a[i] * b[i];
        // //     cout << sum << " " << a[i] << " " << b[i] << " " << a[i] * b[i] << endl;
        // }
        // cout << sum << endl;
        cout << '\n';
    }
    return 0;
}