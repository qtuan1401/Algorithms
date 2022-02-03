#include <bits/stdc++.h>

using namespace std;

map < long long, int > memo;

int solve(long long n) {
    if (n == 0)
        return 0;
    if (memo.count(n))
        return memo[n];
    long long q = n / 10, r = n % 10;
    int res;
    if (1 <= r && r <= 3 && solve(q) <= 1)
        res = 1;
    else if (2 <= r && r <= 6 && solve(q) <= 2)
        res = 2;
    else if (3 <= r && r <= 9 && solve(q) <= 3)
        res = 3;
    else if (4 <= r && r <= 9 && solve(q) <= 4)
        res = 4;
    else if (0 <= r && r <= 2 && solve(q - 1) <= 4)
        res = 4;
    else
        res = 5;
    return memo[n] = res;
}

int main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        memo.clear();
        cout << solve(n) << '\n';
    }
    return 0;
}