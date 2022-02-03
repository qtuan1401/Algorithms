#include <bits/stdc++.h>

using namespace std;

int n, m;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    int mx = (int)log2(m);
    if (mx < n)
        cout << m;
    else 
        cout << m % (1 << n);
    return 0;
}