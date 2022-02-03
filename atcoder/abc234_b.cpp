#include <bits/stdc++.h>

using namespace std;

vector < int > x, y;

long long calc(int i, int j) {
    return (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
}

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    x.resize(n); y.resize(n);
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    long long res = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            res = max(res, calc(i, j));
    cout << fixed << setprecision(10);
    cout << sqrt((double)res);
    return 0;
}