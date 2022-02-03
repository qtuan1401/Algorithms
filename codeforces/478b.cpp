#include <bits/stdc++.h>

using namespace std;

long long n, m;

int main() {
    cin >> n >> m;
    cout << (m * (n / m - 1) + (n % m) * 2) * (n / m) / 2 << " " << ((n - m + 1) * (n - m) / 2);
}