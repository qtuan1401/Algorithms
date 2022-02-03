#include <bits/stdc++.h>

using namespace std;

long long n;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    long long res = 0;
    for(int i = 1; i <= 40; i++) {
        long long val = (1ll << i);
        res = (res + (n / 2) * (1ll << (i - 1)));
        n = (n + 1) / 2;
    }
    cout << res;
    return 0;
}