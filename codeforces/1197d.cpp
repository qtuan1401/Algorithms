#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3e5 + 10;

long long sum[MAXN], a[MAXN], mx[MAXN];
int n, m, k;

long long getSum(int x, int y) {
    return (sum[y] - sum[x - 1]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sum[0] = a[0];
    for(int i = 1; i < n; i++)
        sum[i] = sum[i - 1] + a[i];
    long long ans = mx[0];
    mx[0] = max(0ll, a[0]);
    for(int i = 1; i < m; i++) {
        mx[i] = max(mx[i - 1] + a[i], 0ll);
        ans = max(ans, mx[i]);
    }
    //cout << ans << endl;
    for(int i = m; i < n; i++) {
        mx[i] = max(mx[i], max(0ll, mx[i - m] + getSum(i - m + 1, i) - k));
    //    cout << mx[i] << " " << mx[i - m] << " " << getSum(i - m + 1, i) - k << endl;
        long long temp = 0;
        for(int j = i; j >= i - m + 1; j--) {
            temp += a[j];
            mx[i] = max(mx[i], temp);
        }
    }
    //long long ans = 0;
    //for(int i = 0; i < n; i++)
    //    cout << mx[i] << " ";
    for(int i = 0; i < n; i++)
        ans = max(ans, mx[i]);
    cout << max(0ll, ans - k);
    return 0;
}