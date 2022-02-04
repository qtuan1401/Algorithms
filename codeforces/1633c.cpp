#include <bits/stdc++.h>

using namespace std;

bool calc(long long hc, long long dc, long long hm, long long dm) {
    long long tc = hm / dc + (hm % dc != 0);
    long long tm = hc / dm + (hc % dm != 0);
    return tc <= tm;
}

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        long long hc, dc, hm, dm, w, a;
        cin >> hc >> dc >> hm >> dm;
        int k;
        cin >> k >> w >> a;
        bool ok = false;
        for (int i = 0; i <= k; i++)
            if (calc(hc + 1ll * i * a, dc + 1ll * (k - i) * w, hm, dm)) {
                ok = true;
                break;
            }
        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}