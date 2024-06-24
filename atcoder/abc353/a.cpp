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
    int tests = 1;
    while (tests--) {
        int n, x;
        cin >> n;
        int found = -1;
        cin >> x;
        for (int i = 2; i <= n; i++) {
            int y;
            cin >> y;
            if (y > x && found == -1) {
                found = i;
            } 
        }

        cout << found << '\n';
    }
    return 0;
}