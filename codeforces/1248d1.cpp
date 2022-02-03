#include <bits/stdc++.h>

using namespace std;

const int MAXN = 505;

int sum[MAXN], a[MAXN], mxR[MAXN], mnR[MAXN];
string s;
int n;

int calc(int x, int y) {
    sum[0] = a[0];
    for(int i = 1; i < n; i++) 
        sum[i] = sum[i - 1] + a[i];
    /*if (x == 1 && y == 9) {
        for(int i = 0; i < n; i++)
            cout << sum[i] << " ";
        cout << endl;
    }*/
    mnR[n] = 1e9; mxR[n] = -1e9;
    for(int i = n - 1; i >= 0; i--) {
        mnR[i] = min(mnR[i + 1], sum[i]);
        mxR[i] = max(mxR[i + 1], sum[i]);
    }
    if (sum[n - 1] != 0)
        return 0;
    int mn = 1e9, cnt = 0;
    for(int i = 0; i < n; i++) {
        mn = min(mn, sum[i]);
        if (i == n - 1) {
            if (mn >= 0)
                cnt++;
            return cnt;
        }
        if (mnR[i + 1] - sum[i] < 0)
            continue;
        if (sum[n - 1] - sum[i] + mn < 0)
            continue;
        //if (x == 1 && y == 9)
        //    cout << i << " " << mnR[i + 1] - sum[i] << " " << mxR[i + 1] - sum[i] + mn << " " << mn << endl;
        cnt++;
    }
    return cnt;
}

int main() {
    //freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n;
    cin >> s;
    for(int i = 0; i < n; i++)
        if (s[i] == '(')
            a[i] = 1;
        else a[i] = -1;
    int l = 0, r = 0, ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            swap(a[i], a[j]);
            int res = calc(i, j);
            //cout << res << " ";
            if (ans < res) {
                ans = res;
                l = i;
                r = j;
            }
            swap(a[i], a[j]);
        }
    }
    cout << ans << '\n';
    cout << l + 1 << " " << r + 1;
    return 0;
}