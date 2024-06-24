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

const int LIM = 1e5;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests;
    cin >> tests;
    while (tests--) {
        int r;
        cin >> r;
        long long sumr = 0, sumr1 = 0;
        for (int i = 0; i <= r; i++) {
            sumr += r * r / (4 * i + 1) - r * r / (4 * i + 3);
        }
        sumr = sumr * 4 + 1;
        for (int i = 0; i <= r + 1; i++) {
            sumr1 += (r + 1) * (r + 1) / (4 * i + 1) - (r + 1) * (r + 1) / (4 * i + 3);
        }
        sumr1 = sumr1 * 4 + 1;
        cout << sumr1 - sumr << '\n';
    }
    return 0;
}