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

vector < int > sum;

int getSum(int l, int r) {
    if (l == 0) return sum[r];
    return sum[r] - sum[l - 1];
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests;
    cin >> tests;
    while (tests--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        resetVec < int > (sum, n, 0);
        sum[0] = 1;
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) sum[i] = sum[i - 1] + 1;
            else sum[i] = 1;
        }

        vector < int > fr(n, -1);
        for (int i = n - 1; i >= 0; i--) {
            int l = i - k + 1;
            if (fr[l] == -1) fr[l] = sum[i] == k;
            fr[l] = fr[l] && (sum[i] == k);
            if (l - k >= 0) fr[l - k] = fr[l];
        }
        for (int i = 0; i < n; i++) cout << fr[i] << " ";
        cout << endl;
        bool ok = true;
        int p = -1, l = 0;
        for (int i = 0; i < n; i++) {
            if (sum[i] > k) break;
            if (i % k == 0) l = i;
            if (i + k < n) {
                if (fr[i + 1] == 0) continue;
            }
            if (i % k == 0 && i > 0) {
                ok = (getSum(i - k, i - 1) == k) && (s[i] != s[i - 1]);
                if (ok == false) {
                    break;
                }
            }
            if ((i + 1) % k == 0) {
                if (getSum(l, i) == k && s[n - 1] != s[l]) {
                    p = i;
                    break;
                }
            }
            if (s[i] != s[l]) break;
            cout << l << " " << i << " " << n - (k - i % k - 1) << endl;
            if (sum[i] + getSum(n - (k - i % k - 1), n - 1) == k && s[l] == s[n - 1]) {
                p = i;
                break;
            }
        }
        cout << p << '\n';
    }
    return 0;
}