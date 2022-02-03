#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3e5 + 10;

long long sum[MAXN], a[MAXN];
int n, k;

int main() {
    //freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = n - 1; i >= 0; i--)
        sum[i] = sum[i + 1] + a[i];
    long long res = sum[0];
    sort(sum + 1, sum + n);
    for(int i = n - 1; i > n - k; i--)
        res += sum[i];
    cout << res;
    return 0;
}

