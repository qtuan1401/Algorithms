#include <bits/stdc++.h>

using namespace std;

const int MXN = 5e3 + 5, MXC = 26;
int cnt[MXC][MXC][MXN];
int n;
string s;

inline int getId(int i, int j) {
    return i + j > n ? i + j - n : i + j;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> s;
    s = "#" + s;
    n = s.size() - 1;
    for(int i = 1;i <= n; i++)for(int j = 1; j < n; j++)
        cnt[s[i] - 'a'][s[getId(i, j)] - 'a'][j]++;
    double ans = 0.0;
    for(int i = 0, mx = 0; i < 26; i++, mx = 0){
        for(int sum = 0, j = 1; j <= n; j++, sum = 0){
            for(int k = 0; k < 26; k++)
                sum += (cnt[i][k][j] == 1);
            mx = max(mx, sum);
        }
        ans += 1.0 * mx / n;
    }
    cout << fixed << setprecision(8);
    cout << ans;
    return 0;
}

