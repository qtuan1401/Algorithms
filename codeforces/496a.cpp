#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector < int > a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int diff = 0, mx = 1e9;
    for(int i = 1; i < n; i++)
        diff = max(diff, a[i] - a[i - 1]);
    for(int i = 1; i < n - 1; i++)
        mx = min(mx, max(diff, a[i + 1] - a[i - 1]));
    cout << mx;
    return 0;
}