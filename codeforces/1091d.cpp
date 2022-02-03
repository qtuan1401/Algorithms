#include <bits/stdc++.h>

using namespace std;

const long long mod = 998244353;

long long n, res = 1, fact = 0;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    res = 1;
    for(int i = 1; i <= n; i++)
        res = (res * i) % mod;
    fact = n;
    //n! / j! = n! / (n - 1)! = n
    for(long long i = n - 2; i >= 1; i--) {
        long long num = (fact * i) % mod;
        res = (res + num * (n - i - 1)) % mod;
        fact = (fact * (i + 1)) % mod;
    }
    cout << res;
    return 0;
}