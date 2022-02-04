#include <bits/stdc++.h>

using namespace std;

int getBit(int x, int i) {
    return (x >> i) & 1;
}

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector < int > a(n), cnt(n, 0), pos(n, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    for (int i = 0; i < n; i++) {
        pos[a[i]] = min(pos[a[i]], i);
        a[i]--;
        if (pos[a[i]] != i) {
            int l = pos[a[i]] + 1;
            int r = i;
            cnt[l]++; cnt[r]--;
        }
    }

    for (int i = 1; i < n; i++)
        cnt[i] += cnt[i - 1];
    
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += (cnt[i] > 0);
    cout << ans << '\n';
    return 0;
}