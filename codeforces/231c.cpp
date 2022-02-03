#include <bits/stdc++.h>

using namespace std;

long long sum;

int main() {
    ios_base::sync_with_stdio(0);
    int n, k, ans, cnt = 0;
    cin >> n >> k;
    vector < int > a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    long long sum = 0;
    int j = 0;
    for(int i = 0; i < n; i++) {
        sum += a[i];
        while (1ll * (i - j + 1) * a[i] - sum > k)
            sum -= a[j++];
        if (i - j + 1 > cnt) {
            cnt = i - j + 1;
            ans = a[i];
        }
    }
    cout << cnt << " " << ans;
    return 0;
}