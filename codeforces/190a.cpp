#include <bits/stdc++.h>

using namespace std;

int main() { 
    int n, m;
    cin >> n >> m;
    if (n == 0 && m > 0)
        cout << "Impossible";
    else 
        cout << max(n, m) << " " << n + m - (m > 0);
    return 0;
}