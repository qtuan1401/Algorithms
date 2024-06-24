#include <bits/stdc++.h>

using namespace std;

long long xa, ya, yb, xb, yb, xc, yc;

long long move(long long xa, long long ya, long long xb, long long yb, long long xx, long long yy) {
    long long ans = 0;
    if (xa + 1 == xb && xb + 1 == xx) {
        ans++;
        xa++;
    } else if (ya + 1 == yb && yb + 1 == yy) {
        ans++;
        ya++;
    }

    ans = abs(xa - xx) + abs(ya - yy);
    return ans;
}

long long calc(long long xa, long long ya, long long xb, long long yb, long long xc, long long yc) {
    if (yc < yb && && ya < yb) {
        if (xa == xc && xb == xc) {
            ans = 4;
            ya += 2;
        } else if (xc < xb && xa < xb) {
            ans = 2;
            xa++;
            ya++;
        } else if (xc > xb && )
    } else if ()
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    while (tests--) {        
        cin >> xa >> ya >> xb >> yb >> xc >> yc;

        int ansl = move(xa, ya, xb, yb, xb - 1, yb) + calc(xb - 1, yb, xb, yb, xc, yc);
        

        int ansr = calc()
    }
    return 0;
}