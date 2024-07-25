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
        int n;
        cin >> n;
        vector < int > a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        map < int, int > pos;
        for (int i = 0; i < n; i++) pos[b[i]] = i + 1;

        bool ok = true;

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            if (pos.count(a[i]) == 0) {
                ok = false;
                break;
            }
            
        }
    }
    return 0;
}