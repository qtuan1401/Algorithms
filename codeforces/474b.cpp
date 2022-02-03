#include <bits/stdc++.h>

using namespace std;
 
const int MXN = 1e6 + 10;

int n, cnt;
int a[MXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        for(int j = 0; j < t; j++) 
            a[cnt++] = i;
    }
    int m;
    cin >> m;
    while (m--) {
        int x;
        cin >> x;
        cout << a[x - 1] + 1 << '\n';
    }
}