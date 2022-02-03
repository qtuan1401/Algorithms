#include <bits/stdc++.h>

using namespace std;

const int MXN = 2e5 + 10;
const int MOD = 1e9 + 7;

int a[MXN];
int n;

long long calcPow(long long a, long long n) {
    long long res = 1;
    while (n > 0) {
        if (n & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        n >>= 1;
    }
    return res;
}

int main() {
    //freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);
    int len = 1;

    vector < pair < int, int > > num;
    a[n] = a[n - 1] + 1;
    for(int i = 1; i <= n; i++) {
        if (a[i] == a[i - 1])
            len++;
        else {
            num.push_back(make_pair(a[i - 1], len));
            len = 1;
        }
    }
    //for(int i = 0; i < num.size(); i++)
    //    cout << num[i].first << " " << num[i].second << endl;
    long long res = 1;
    long long cnt = 0;
    for(int i = 0; i < num.size(); i++) {
        res = (res * calcPow(res, num[i].second)) % MOD;
        res = (res * calcPow(num[i].first, (1ll * num[i].second * (num[i].second + 1) / 2 % (MOD - 1) * (cnt + 1)) % (MOD - 1))) % MOD;
        cnt = (cnt + num[i].second * (cnt + 1)) % (MOD - 1);   
        //cout << res << " * " << cnt << endl;
    }

    cout << res;
    return 0;
}

