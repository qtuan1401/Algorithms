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

int calc(pii a, pii b) {
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    while (tests--) {
        pii a, b, c;
        cin >> a.first >> a.second;
        cin >> b.first >> b.second;
        cin >> c.first >> c.second;

        vector < int > dist;
        dist.push_back(calc(a, b));
        dist.push_back(calc(b, c));
        dist.push_back(calc(a, c));

        sort(dist.begin(), dist.end());

        if (dist[0] + dist[1] == dist[2]) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}