#include <bits/stdc++.h>

using namespace std;

long long genMin(long long x) {
    long long ans = 1;
    for (long long i = 1; i < x; i++) ans *= 10;
    return ans;
}

long long genMax(long long x) {
    long long ans = 9;
    for (long long i = 1; i < x; i++) ans = ans * 10 + 9;
    return ans;
}

long long cntDigit(long long x) {
    long long ans = 0;
    while (x > 0) {
        ans++;
        x /= 10;
    }
    return ans;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    long long tests;
    cin >> tests;
    while (tests--) {
        long long a, b, c;
        long long k;
        cin >> a >> b >> c >> k;

        if (max(a, b) > c || max(a, b) + 1 < c) {
            cout << "-1\n";
            continue;
        }

        long long nc = genMin(c);
        long long tot = k;
        long long ansA = -1, ansB = -1, ansC = -1;
        for (long long i = genMin(a); i <= genMax(a); i++) {
            long long l = genMin(c) - i;
            if (cntDigit(l) > b) continue;
            if (cntDigit(l) < b) l = genMin(b);

            if (cntDigit(i + l) > c) continue;
            
            long long r = genMax(b);
            if (cntDigit(i + r) > c) r = genMax(c) - i;
            if (cntDigit(r) < b) continue;
            // cout << i << " " << l << " " << r << " " << tot << endl;
            if (tot <= r - l + 1) {
                ansA = i;
                ansB = l + tot - 1;
                ansC = ansA + ansB;
                break;
            } else tot -= r - l + 1;
        }


        if (ansA == -1) {
            cout << "-1\n";
        } else {
            cout << ansA << " + " << ansB << " = " << ansC << '\n';
        }
    }
    return 0;
}