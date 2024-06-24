#include <bits/stdc++.h>

using namespace std;

template < class T >
void resetVec(vector < T > & a, int sz, T val) {
    a.clear();
    a.resize(sz, val);
}

typedef long double ld;
typedef long long ll;
typedef pair < int, int > pii;

bool check(int x, int y) {
    if (x / 2 == y || y / 2 == x) return true;
    return false;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests;
    cin >> tests;
    while (tests--) {
        int n;
        cin >> n;
        vector < int > a(n), ans(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            ans[i] = a[i];
        }
        int p = -1;
        for (int i = 0; i < n; i++) {
            if (a[i] != -1) {
                p = i;
                int cnt = 0;
                while (i > 0) {
                    i--;
                    cnt = 1 - cnt;
                    if (cnt & 1) ans[i] = ans[i + 1] * 2;
                    else ans[i] = ans[i + 1] / 2;
                }
                break;
            }
        }

        if (p == -1) {
            for (int i = 0; i < n; i++) {
                if (i & 1) cout << 1 << " ";
                else cout << 2 << " ";
            }
            cout << '\n';
            continue;
        }

        int l = p, r = p;
        bool ok = true;
        for (int r = p + 1; r < n; r++) {
            while (r < n && a[r] == -1) r++;
            if (r == n) {
                for (int i = l + 1, cnt = 0; i < n; i++, cnt = 1 - cnt) {
                    if (cnt % 2 == 0) ans[i] = ans[i - 1] * 2;
                    else ans[i] = ans[i - 1] / 2;
                }
            } else {
                int pr = r, pl = l;
                int vr = a[r];
                int vl = a[l];
                while (vr != vl && pl + 1 < pr) {
                    if (vr >= vl) {
                        vr /= 2;
                        pr--;
                        ans[pr] = vr;
                    } else {
                        vl /= 2; 
                        pl++;
                        ans[pl] = vl;
                    }
                }
                // cout << vl << " " << vr << " " << pl << " " << pr << endl;
                for (int j = pl + 1, id = 0; j < pr; j++) {
                    if (id == 0) ans[j] = ans[j - 1] * 2;
                    else ans[j] = ans[j - 1] / 2;
                    id = 1 - id;
                }
                for (int i = l + 1; i <= r; i++) 
                    if (check(ans[i - 1], ans[i]) == false) {
                        ok = false;
                    }
                if (!ok) break;
            }
            l = r;
        }

        if (!ok) cout << "-1\n";
        else {
            for (int i = 0; i < n; i++) cout << ans[i] << " ";
            cout << '\n';
        }
    }
    return 0;
}