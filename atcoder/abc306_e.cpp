#include <bits/stdc++.h>

using namespace std;

void remove(set < int > & s, map < int, int > & mp, int x) {
    mp[x]--;
    if (mp[x] == 0) s.erase(s.find(x));
}

void add(set < int > & s, map < int, int > & mp, int x) {
    mp[x]++;
    if (mp[x] == 1) s.insert(x);
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    while (tests--) {
        int n, k, q;
        cin >> n >> k >> q;

        set < int > small, big;
        map < int, int > cntSmall, cntBig;
        small.insert(0);
        big.insert(0);
        cntSmall[0] = n - k;
        cntBig[0] = k;
        vector < int > a(n);
        for (int i = 0; i < n; i++) a[i] = 0;
        long long ans = 0;
        int cntS = n - k, cntB = k;
        while (q--) {
            int x, y;
            cin >> x >> y;
            x--;

            int s = *small.rbegin();
            int b = *big.begin();

            if (cntSmall[a[x]] != 0) {
                remove(small, cntSmall, a[x]);
                cntS--;
            } else {
                remove(big, cntBig, a[x]);
                ans -= a[x];
                cntB--;
            }

            add(small, cntSmall, y);
            cntS++;
            if (cntS > n - k) {
                remove(small, cntSmall, s);
                add(big, cntBig, s);
                cntS--;
                ans += s;
            }

            while (true) {
                int s = *small.rbegin();
                int b = *big.begin();
                if (s <= b) break;
                ans -= b;
                remove(big, cntBig, b);
                remove(small, cntSmall, s);

                add(big, cntBig, s);
                add(small, cntSmall, b);
                ans += s;
            }
            
            a[x] = y;

            // for (auto & it : small) cout << (it) << " ";
            // for (auto & it : big) cout << (it) << " ";
            cout << ans << '\n';
        }
    }
    return 0;
}