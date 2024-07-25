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

long long getSum(vector < long long > & sum, int l, int r) {
    if (l > r || l < 0 || r < 0) return 0;
    if (l == 0) return sum[r];
    return sum[r] - sum[l - 1];
}

void process(vector < int > & a, vector < int > & b, vector < int > & c, int & la, int & ra, int & lb, int & rb, int & lc, int & rc) {
    int n = a.size();
    vector < long long > sb(n), sc(n);
    sb[0] = b[0]; sc[0] = c[0];
    for (int i = 1; i < n; i++) {
        sb[i] = sb[i - 1] + b[i];
        sc[i] = sc[i - 1] + c[i];
    }
    long long avg = ceil(1.0 * sb[n - 1] / 3);
    vector < int > ca(n, -1);
    long long sum = 0;

    for (int i = 0, j = 0; i < n; i++) {
        sum += a[i];
        while (sum - a[j] >= avg) {
            sum -= a[j];
            j++;
        }
        
        if (sum >= avg) {
            ca[i] = j;
        }
    }
    for (int i = 0; i < n; i++) {
        if (ca[i] == -1) continue;
        int l = ca[i];
        if (l == 0 || i + 1 >= n) continue;
        long long sl = getSum(sb, 0, l - 1);
        long long sr = getSum(sc, i + 1, n - 1);
        if (sl >= avg && sr >= avg) {
            la = l;
            ra = i;
            lb = 0;
            rb = l - 1;
            lc = i + 1;
            rc = n - 1;
            return;
        }

        sl = getSum(sc, 0, l - 1);
        sr = getSum(sb, i + 1, n - 1);
        if (sl >= avg && sr >= avg) {
            la = l;
            ra = i;
            lc = 0;
            rc = l - 1;
            lb = i + 1;
            rb = n - 1;
            return;
        }
    }
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
        vector < int > a(n), b(n), c(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        for (int i = 0; i < n; i++) cin >> c[i];

        int la = -1, ra = -1, lb = -1, rb = -1, lc = -1, rc = -1;
        process(a, b, c, la, ra, lb, rb, lc, rc);
        if (la != -1) {
            cout << la + 1 << " " << ra + 1 << " " << lb + 1 << " " << rb + 1 << " " << lc + 1 << " " << rc + 1 << '\n';
            continue;
        }
        process(b, a, c, lb, rb, la, ra, lc, rc);
        if (la != -1) {
            cout << la + 1 << " " << ra + 1 << " " << lb + 1 << " " << rb + 1 << " " << lc + 1 << " " << rc + 1 << '\n';
            continue;
        }
        process(c, a, b, lc, rc, la, ra, lb, rb);
        if (la != -1) {
            cout << la + 1 << " " << ra + 1 << " " << lb + 1 << " " << rb + 1 << " " << lc + 1 << " " << rc + 1 << '\n';
            continue;
        }

        cout << "-1\n";
    }
    return 0;
}