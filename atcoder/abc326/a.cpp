#include <bits/stdc++.h>

#define vall(a) (a.begin(), a.end())

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    while (tests--) {
        int x, y;
        cin >> x >> y;

        bool ok = false;
        if (x > y && x - y <= 3) ok = true;
        if (x < y && y - x <= 2) ok = true;

        if (ok) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}