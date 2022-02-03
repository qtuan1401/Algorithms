#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    cout << min(n, min(m, (n + m) / 3));
    return 0;
}