#include <bits/stdc++.h>

using namespace std;

int n, m, k;
int a[1005];

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> k;
    for(int i = 0; i <= m; i++)
        cin >> a[i];
    int cnt = 0;
    for(int i = 0; i < m; i++)
        cnt += (__builtin_popcount(a[i] ^ a[m]) <= k);
    cout << cnt;
}