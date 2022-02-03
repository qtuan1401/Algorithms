#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e4 + 10;

int len[55], a[55][MAXN], cnt[MAXN];
int m, n;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> m >> n;
    for(int i = 0; i < m; i++) {
        cin >> len[i];
        for(int j = 0; j < len[i]; j++) {
            cin >> a[i][j];
            cnt[a[i][j]]++;
        }
    }
    for(int i = 0; i < m; i++) {
        for(int j = i + 1; j < m; j++) {
            for(int k = 1; k <= n; k++)
                cnt[k] = 0;
            for(int k = 0; k < len[i]; k++)
                cnt[a[i][k]]++;
            for(int k = 0; k < len[j]; k++)
                cnt[a[j][k]]++;
            int mx = 0;
            for(int k = 1; k <= n; k++)
                mx = max(mx, cnt[k]);
            if (mx <= 1) {
                cout << "impossible";
                return 0;
            } 
        }
    }
    cout << "possible";
    return 0;
}