#include <bits/stdc++.h>
using namespace std;
 
const int MXN = 1e6 + 10;

int a[4][MXN], cnt[2][2];
 
int main() {
    ios_base :: sync_with_stdio(0); 
    int n, m;
    cin >> n >> m;
    if (n > 3) {
        cout << -1;
        return 0;
    }
    if (n == 1) {
        cout << 0;
        return 0;
    }
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < m; j++)
            a[i][j] = s[j] - '0';
    }
    for(int i = 0; i < m; i++) {
        int cnt12 = (a[0][i] + a[1][i] + i) % 2;
        int cnt13 = 0;
        if (n == 3)
            cnt13 = (a[0][i] + a[2][i]) % 2;
        cnt[cnt12][cnt13]++;
    }
    cout << m - max(max(cnt[0][0], cnt[0][1]), max(cnt[1][0], cnt[1][1]));
}