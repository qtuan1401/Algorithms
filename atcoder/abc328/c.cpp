#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair < int, int > pii;

int get(vector < int > & sum, int l, int r) {
    if (l > r) return 0;
    if (l == 0) return sum[r];
    return sum[r] - sum[l - 1];
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    while (tests--) {
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;

        vector < int > sum(n);
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) sum[i] = 1; 
        }

        for (int i = 1; i < n; i++) sum[i] += sum[i - 1];
        
        while (q--) {
            int l, r;
            cin >> l >> r;
            l--; r--;
            cout << get(sum, l, r - 1) << '\n';
        }
    }
    return 0;
}