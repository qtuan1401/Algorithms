#include <bits/stdc++.h>

using namespace std;

const int MAXN = 8005;

int n, k;
int cnt[MAXN];
vector < int > a;

int main() {
    //freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    } 

    for(int i = 1; i <= k; i++)
        if (cnt[i] > 0)
            a.push_back(cnt[i]);
    sort(a.begin(), a.end());
    n = a.size();
    long long ans = 1e18;
    for(int r = 0; r < n; r++) {
        //cout << a[r] << " ";
        int mx = 0;
        //cout << r / 2 << endl;
        for(int i = 0; i < (r + 1) / 2; i++) {
        //    cout << a[i] << " * " << a[r - i] << endl;
            mx = max(mx, a[i] + a[r - i]);
        }
        if (r % 2 == 0)
            mx = max(mx, a[r / 2]);
        //cout << r << " " << mx << " " << (r / 2) + (r % 2 == 0) << " " <<  (n - 1) - r << endl;
        ans = min(ans, 1ll * max(mx, a[n - 1]) * (((r + 1) / 2) + (r % 2 == 0) + (n - 1) - r));
    }
    cout << ans;
    return 0;
}