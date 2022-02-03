#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    int n, l;
    cin >> n >> l;
    vector < int > a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    int mx = max(a[0], l - a[n - 1]) * 2;
    for(int i = 1; i < n; i++)
        mx = max(mx, a[i] - a[i - 1]);
    cout << fixed << setprecision(15);
    cout << 1.0 * mx / 2;
    return 0;
}