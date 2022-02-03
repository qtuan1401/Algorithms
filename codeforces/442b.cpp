#include <bits/stdc++.h>

using namespace std;

double p[105];
int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> p[i];
    sort(p, p + n);
    double sum = p[n - 1], res = p[n - 1], mul = (1.0 - p[n - 1]);
    cout << fixed << setprecision(10);
    if (sum == 1) {
        cout << sum;
        return 0;
    }
    for(int i = n - 2; i >= 0; i--) { 
        sum = sum * (1 - p[i]) + p[i] * mul;
        mul *= (1 - p[i]);
        res = max(res, sum);
    }
    cout << res;
    return 0;
}