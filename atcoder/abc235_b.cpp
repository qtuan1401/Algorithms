#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector < int > a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int cur = 0;
    for (int i = 1; i < n; i++) {
        if (a[cur] >= a[i]) break;
        cur = i;
    }
    cout << a[cur] << '\n';
    return 0;
}