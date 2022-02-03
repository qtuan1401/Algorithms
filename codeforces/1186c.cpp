#include <bits/stdc++.h>

using namespace std;

string a, b;
int cnt, res;
int s[1000005];

int main() {
    ios_base::sync_with_stdio(0);
    cin >> a;
    cin >> b;
    int n = a.size(), m = b.size();
    a = '#' + a; b = '#' + b;
    for(int i = 1; i <= n; i++)
        s[i] += s[i - 1] + (a[i] == '1');
    for(int i = 1; i <= m; i++)
        cnt += (b[i] == '1');
    for(int i = 1; i <= n - m + 1; i++) {
        int r = i + m - 1;
        res += ((s[r] - s[i - 1] + cnt) % 2 == 0);
    }
    cout << res;
    return 0;
}