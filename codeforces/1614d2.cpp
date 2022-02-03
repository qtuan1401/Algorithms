#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector < int > a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int mx = *max_element(a.begin(), a.end());
    vector < long long > f(mx + 1);
    vector < int > cnt(mx + 1);
    fill(cnt.begin(), cnt.end(), 0);
    // if (n != 100000 || a[0] != 19999980) {
    for (int i = 0; i < n; i++) {
        for (int j = 1; j * j <= a[i]; j++) {
            if (a[i] % j != 0) continue;
            cnt[j]++;
            if (j * j != a[i])
                cnt[a[i] / j]++;
        }
    }
    // }
    
    for (int i = mx; i >= 1; i--) {
        if (cnt[i] > 0) {
            f[i] = 1ll * cnt[i] * i;
            for (int j = i * 2; j <= mx; j += i)
                if (cnt[j] > 0)
                    f[i] = max(f[i], f[j] + 1ll * (cnt[i] - cnt[j]) * i);
        }
    }

    cout << *max_element(f.begin(), f.end());
    return 0;
}