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

bool check(int i, int k, int n, vector < int > & a, string & s) {
    if (a[i + 1] == 1) return true;
    if (s[i] != s[i + 1]) return a[i + 1] != 0;
    int len = sum[i + k];
    len -= sum[i];
    if (len != k) return false;
    if (i + k + 1 >= n) return true;
    return a[i + k + 1];
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
            if (i + k - 1 < n) {
                fr[i] = sum[i + k - 1] == k;
                if (i + k < n && fr[i + k] != -1) fr[i] &= fr[i + k];
            }
        }
        // for (int i = 0; i < n; i++) cout << fr[i] << " ";
        // cout << '\n';
        if (fr[0] == 1) {
            cout << n << " ";
            cout << '\n';
            continue;
        }
        bool ok = true;
        int p = -1, l = 0;
        for (int i = 0; i < n - k; i++) {
            // cout << i << endl;
            if (sum[i] > k) break;
            if (i % k == 0) {
                l = i;
                if (i > 0 && (s[i - 1] == s[i] || sum[i - 1] != k)) {
                    break;
                }
            }

            if (check(i, k, n, fr, s) == false) continue;
            // cout << i % k << " " << k - 1 << endl;
            if (i % k == k - 1) {
                // cout << sum[i] << " " << endl;
                if (sum[i] == k && s[i] != s[n - 1]) {
                    p = i + 1;
                    break;
                }
            } else {
                if (s[i] != s[n - 1]) continue;
                int sufLen = k - ((i + 1) % k);
                if (sum[n - 1] != sufLen) continue;
                if (sum[i] + sufLen == k) {
                    p = i +1;
                    break;
                }
            }

        }
        cout << p << '\n';
    }
    return 0;
}