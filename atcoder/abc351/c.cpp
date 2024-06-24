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
        int n;
        cin >> n;
        vector < int > balls;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            balls.push_back(x);
            while (balls.size() > 1 && balls[balls.size() - 1] == balls[balls.size() - 2]) {
                balls.pop_back();
                balls.back()++;
            }
        }

        cout << balls.size() << '\n';
    }
    return 0;
}