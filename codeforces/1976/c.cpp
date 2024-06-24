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

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests;
    cin >> tests;
    while (tests--) {
        int n, m;
        cin >> n >> m;
        vector < int > a(n + m + 1), b(n + m + 1);
        vector < int > d(n + m + 1, 0), t(n + m + 1, 0);
        for (int i = 0; i < n + m + 1; i++) cin >> a[i];
        for (int i = 0; i < n + m + 1; i++) cin >> b[i];
        int swapPoint = n + m, flag = 0;
        long long sumD = 0, sumT = 0;
        for (int i = 0; i < n + m; i++) {
            if (i > 0) {
                d[i] = d[i - 1];
                t[i] = t[i - 1];
            }
            if (a[i] > b[i]) {
                if (d[i] < n) {
                    d[i]++;
                    sumD += a[i];
                } else {
                    swapPoint = min(swapPoint, i);
                    flag = 0;
                    t[i]++;
                    sumT += b[i];
                }
            } else {
                if (t[i] < m) {
                    t[i]++;
                    sumT += b[i];
                } else {
                    swapPoint = min(swapPoint, i);
                    flag = 1;
                    d[i]++;
                    sumD += a[i];
                }
            }
        }
        vector < long long > ans(n + m + 1);
        ans[n + m] = sumD + sumT;
        int preD = 0, preT = 0;
        for (int i = 0; i < n + m; i++) {
            if (i > 0) {
                preD = d[i - 1];
                preT = t[i - 1];
            }
            long long td = sumD, tt = sumT;
            if (i >= swapPoint) {
                if (flag == 0) {
                    tt -= b[i];
                    tt += b[n + m];
                } else {
                    td -= a[i];
                    td += a[n + m];
                }
                ans[i] = td + tt;
                continue;
            }
            if (d[i] > preD) {
                td -= a[i];
                if (flag == 1) td += a[n + m];
                else {
                    td += a[swapPoint];
                    tt -= b[swapPoint];
                    tt += b[n + m];
                }
            } else {
                tt -= b[i];
                if (flag == 0) tt += b[n + m];
                else {
                    tt += b[swapPoint];
                    td -= a[swapPoint];
                    td += a[n + m];
                } 
            }

            ans[i] = td + tt;
        }

        for (int i = 0; i < n + m + 1; i++) cout << ans[i] << " ";
        cout << '\n'; 
    }
    return 0;
}