#include <bits/stdc++.h>

using namespace std;

long long n, m, k;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> k >> m;
    vector < long long > a(n);
    double sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a.begin(), a.end());
    cout << fixed << setprecision(15);
    double mx = (sum + min(m, n * k)) / n;
    //cout << mx << endl;
    for(int i = 0; i < min(n - 1, m); i++) {
        sum -= a[i];
        mx = max(mx, (sum + min(m - i - 1, (n - i - 1) * k)) / (n - i - 1));
    }
    cout << mx;
    return 0;
}