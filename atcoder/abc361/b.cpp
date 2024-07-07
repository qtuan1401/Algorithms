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

bool check(vector < int > & a, int x, int y, int z, int type) {
    if (type == 0) {
        if (a[0] > x || a[1] > y || a[2] > z) return false;
        return x < a[3] && y < a[4] && z < a[5];
    } else {
        if (a[0] >= x || a[1] >= y || a[2] >= z) return false;
        return x <= a[3] && y <= a[4] && z <= a[5];
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    while (tests--) {
        vector < int > a(12);
        for (int i = 0; i < 12; i++) cin >> a[i];
        bool ok = true;
        for (int i = 0; i < 3; i++) {
            if (max(a[i], a[i + 6]) >= min(a[i + 3], a[i + 9])) {
                ok = false;
                break;
            }
        }
        if (ok) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}