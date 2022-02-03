#include<bits/stdc++.h>

using namespace std;

long long n, x, m, a, b;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> x;
    for(int i = 0; i < n; i++) {
        long long y;
        cin >> y;
        a = a * x + y;
    }
    cin >> m >> x;
    for(int i = 0; i < m; i++) {
        long long y;
        cin >> y;
        b = b * x + y;
    }
    if (a == b) cout << "=";
    else if (a < b) cout << "<";
    else cout << ">";
}