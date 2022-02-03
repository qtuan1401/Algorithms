#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector < int > a(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    int s, t;
    cin >> s >> t;
    if (s > t)
        swap(s, t);
    cout << min(a[t - 1] - a[s - 1], a[n] - a[t - 1] + a[s - 1]);
    return 0;
}