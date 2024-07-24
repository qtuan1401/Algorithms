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
        int r, g, b;
        cin >> r >> g >> b;
        string c;
        cin >> c;
        if (c == "Red") r = 200;
        if (c == "Green") g = 200;
        if (c == "Blue") b = 200;
        cout << min(min(r, g), b); 
    }
    return 0;
}