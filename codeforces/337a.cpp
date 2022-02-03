#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n, m, mn = 1e9;
    cin >> n >> m;
    vector < int > a(m);
    for(int i = 0; i < m; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    for(int i = 0; i < m - n + 1; i++)
        mn = min(mn, a[i + n - 1] - a[i]);
    cout << mn;
    return 0;
}