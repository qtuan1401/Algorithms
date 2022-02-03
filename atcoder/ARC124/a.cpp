#include <bits/stdc++.h>

using namespace std;

const int LIM_N = 1e3 + 10;

int sr[LIM_N], sl[LIM_N];
int n, m;

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int k;
        char c;
        cin >> c >> k;
        if (c == 'L')
            sl[k] = 1;
        else
            sr[k] = 1;
    }
    
    for (int i = n; i >= 1; i--)
        sl[i] += sl[i + 1];
    for (int i = 1; i <= n; i++)
        sr[i] += sr[i - 1];


    long long res = 1;
    for (int i = 1; i <= n; i++) {
        if (sl[i] - sl[i + 1] > 0 || sr[i] - sr[i - 1] > 0)
            continue;
        int cnt = m - sl[i] - sr[i];
        // cout << cnt << endl;
        res = (res * cnt) % 998244353;
    }
    cout << res;
    return 0;
}