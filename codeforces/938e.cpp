#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;

long long calc(long long a, long long n) {
    long long res = 1;
    while (n > 0) {
        if (n & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        n /= 2;
    }
    return res;
}

long long n;
long long fact[1000005];

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    vector < long long > a(n);
    for(long long i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    vector < long long > sum;
    sum.push_back(1);
    for(long long i = 1; i < n; i++)
        if (a[i] == a[i - 1]) 
            sum[sum.size() - 1]++;
        else {
            sum.push_back(1);
        }
    a.erase(unique(a.begin(), a.end()), a.end());
    fact[1] = 1;
    for(int i = 2; i <= n; i++)
        fact[i] = (fact[i - 1] * i) % MOD;
    for(int i = 1; i < sum.size(); i++)
        sum[i] += sum[i - 1];
    long long res = 0;
    //cout << a[0] * fact[n] * calc(n, MOD - 2) % MOD;
    for(int i = 0; i < (int)a.size() - 1; i++) {
        res += (sum[i] - (i == 0 ? 0 : sum[i - 1])) * (((a[i] * fact[n]) % MOD * calc(n - (i == 0 ? 0 : sum[i - 1]), MOD - 2)) % MOD);
        res %= MOD;
        //cout << res << " " << a[i] * fact[n] << endl;
    }
    cout << res;
    return 0;
}