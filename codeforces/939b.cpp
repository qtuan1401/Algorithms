#include <bits/stdc++.h>

using namespace std;

long long n;
int k;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    long long mn = 1e18;
    long long res = 0;
    int pos = -1;
    for(int i = 0; i < k; i++) {
        long long x;
        cin >> x;
        if (n % x < mn) {
            pos = i + 1;
            mn = n % x;
            res = n / x;
        }
    }
    cout << pos << " " << res;
    return 0;
}