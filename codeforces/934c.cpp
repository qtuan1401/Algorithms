#include <bits/stdc++.h>

using namespace std;

const int MXN = 2e3 + 10;

int n;
int cnt[MXN], f[MXN][2], a[MXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i < n; i++) 
        cin >> a[i];
    for(int i = n - 1; i > 0; i--)
        cnt[i] = cnt[i + 1] + (a[i] == 2);
    for(int i = 0; i < n; i++) 
        if (a[i] == 1) {
            f[i][0] = f[i - 1][0] + 1;
        } else {
            f[i][1] = max(f[i - 1][0], f[i - 1][1]) + 1;
            f[i][0] = f[i - 1][0];
        }
    int res = max(f[n - 1][1], f[n - 1][0]);
    //cout << res << endl;
    for(int i = n - 1; i >= 0; i--) {
        int cnt1 = (a[i] == 1), cnt2 = (a[i] == 2);
        for(int j = i - 1; j >= 0; j--) {
            if (a[j] == 1)
                cnt1++;
            else 
                cnt2 = max(cnt2, cnt1) + 1;
            res = max(res, cnt2 + max(f[j - 1][0], f[j - 1][1]) + cnt[i + 1]);
        }
    }
    cout << res;
}