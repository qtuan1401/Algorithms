#include <bits/stdc++.h>

using namespace std;

vector < int > num;

void sieve(int n) {
    vector < int > prime(n + 1, false);
    for(int i = 2; i * i <= n; i++) {
        if (!prime[i]) {
            for(int j = i * i; j <= n; j += i)
                prime[j] = true;
        }
    }

    for (int i = 2; i <= n; i++)
        if (!prime[i])
            num.push_back(i);
}

int main() {
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    sieve(1e5);
    while (T--) {
        int n;
        cin >> n;
        int res = 0;
        for (int i = num.size() - 1; i >= 0; i--)
            if (num[i] <= n - 1) {
                res = num[i];
                break;
            }
        long long sum = n - 1;
        res--;
        for (int i = 1; i <= n; i++) {
            int nxt = i + max(1, res);
            if (res == 0) break;
            sum += nxt - i;
            res--;
        }
        cout << sum << '\n';
    }
    return 0;
}