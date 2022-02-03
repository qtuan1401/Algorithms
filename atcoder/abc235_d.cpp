#include <bits/stdc++.h>

using namespace std;

const int INF = 1e7; 

int a, n;
vector < int > marked, dp;

inline int calc(int x) {
    int num = x % 10;
    if (num == 0) return INF;
    x /= 10;
    vector < int > digits;

    while (x > 0) {
        digits.push_back(x % 10);
        x /= 10; 
    }
    
    reverse(digits.begin(), digits.end());
    for (int &digit : digits)
        num = num * 10 + digit;
    return num;
}

int memo(int x) {
    if (x == n) return 0;
    if (marked[x] == 1) return INF;
    if (marked[x] == 2) return dp[x];
    int res = INF;
    marked[x] = 1;
    if (x < INF / a) res = memo(x * a) + 1;
    res = min(res, memo(calc(x)) + 1);
    dp[x] = res;
    marked[x] = 2;
    return dp[x];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> a >> n;
    dp.resize(INF + 1, INF); marked.resize(INF + 1, 0);
    int ans = memo(1ll);
    if (ans >= INF) ans = -1;
    cout << ans << '\n';
    return 0;
}