#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    vector < int > h(n), f(n);
    for (int i = 0; i < n; i++)
        cin >> h[i];

    fill(f.begin(), f.end(), int(2e9));
    f[0] = 0;
    for (int i = 1; i < n; i++)
        for (int j = i; j >= i - k && j >= 0; j--)
            f[i] = min(f[i], f[j] + abs(h[i] - h[j]));
    
    cout << f[n - 1];
    return 0;
}