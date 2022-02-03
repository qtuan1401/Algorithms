#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n;
    cin >> n;
    long long l = -(1ll << 31);
    long long r = (1ll << 31) - 1;
    if (n < l || n > r) cout << "No";
    else cout << "Yes";
    return 0;
}