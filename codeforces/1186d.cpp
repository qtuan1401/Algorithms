#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector < int > a(n), isInt(n), isNeg(n);
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        double x;
        cin >> x;
        a[i] = int(x);
        sum += a[i];
        isNeg[i] = (x < 0);
        isInt[i] = (int(x) == x);
    }

    for (int i = 0; i < n; i++) {
        if (isInt[i] == 1) continue;
        if (sum < 0 && !isNeg[i])
            sum++, a[i]++;
        if (sum > 0 && isNeg[i])
            sum--, a[i]--;
        if (sum == 0) break;
    }

    for (int i = 0; i < n; i++)
        cout << a[i] << '\n';
    return 0;
}