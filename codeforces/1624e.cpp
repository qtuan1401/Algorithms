#include <bits/stdc++.h>

using namespace std;

struct Pair {
    int l, r, i;
    Pair(int _l, int _r, int _i) {
        l = _l;
        r = _r;
        i = _i; 
    }
};

bool operator == (const Pair& lhs, const Pair& rhs) {
    return lhs.i == rhs.i && lhs.l == rhs.l && lhs.r == rhs.r;
}

bool operator != (const Pair& lhs, const Pair& rhs) {
    return !(lhs == rhs);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> m >> n;
        Pair init = Pair(0, 0, 0);
        vector < Pair > pairs(100, init), tris(1000, init);
        for (int i = 0; i < m; i++) {
            string s;
            cin >> s;
            for (int j = 0; j + 1 < s.size(); j++) {
                int x = s[j] - '0';
                int y = s[j + 1] - '0';
                if (pairs[x * 10 + y] == init)
                    pairs[x * 10 + y] = Pair(j + 1, j + 2, i + 1);
            }
            for (int j = 0; j + 2 < s.size(); j++) {
                int x = s[j] - '0', y = s[j + 1] - '0', z = s[j + 2] - '0';
                int num = x * 100 + y * 10 + z;
                if (tris[num] == init) {
                    tris[num] = Pair(j + 1, j + 3, i + 1);
                }
            }
        }
        string t;
        cin >> t;
        vector < Pair > f(n, init);
        if (n >= 2)
            f[1] = pairs[(t[0] - '0') * 10 + (t[1] - '0')];
        if (n >= 3)
            f[2] = tris[(t[0] - '0') * 100 + (t[1] - '0') * 10 + (t[2] - '0')];
        for (int i = 3; i < n; i++) {
            if (f[i - 2] != init) {
                int x = t[i - 1] - '0', y = t[i] - '0';
                int num = x * 10 + y;
                f[i] = pairs[num];
            } else if (f[i - 3] != init) {
                int x = t[i - 2] - '0', y = t[i - 1] - '0', z = t[i] - '0';
                int num = x * 100 + y * 10 + z;
                f[i] = tris[num];
            }
        }
        if (f[n - 1] == init) {
            cout << "-1\n";
        } else {
            vector < Pair > ans;
            n--;
            while (n > 0) {
                if (f[n - 2] != init) {
                    ans.push_back(f[n]);
                    n -= 2;
                } else {
                    ans.push_back(f[n]);
                    n -= 3;
                }
            }
            reverse(ans.begin(), ans.end());
            cout << ans.size() << '\n';
            for (Pair &p : ans) {
                cout << p.l << " " << p.r << " " << p.i << '\n';
            }
        }
        
    }
    return 0;
}