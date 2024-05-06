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
        int n, k;
        cin >> n >> k;
        vector < pii > a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].first;
            a[i].second = i;
        }

        sort(a.begin(), a.end());

        deque < int > mn, mx;
        int ans = n + 1;
        for (int i = 0; i < n; i++) {
            while (mn.size() && a[mn.back()].second >= a[i].second) mn.pop_back();
            while (mx.size() && a[mx.back()].second <= a[i].second) mx.pop_back();
            mn.push_back(i);
            mx.push_back(i);
            if (mn.front() + k <= i) mn.pop_front();
            if (mx.front() + k <= i) mx.pop_front();
            if (i + 1 >= k) {
                ans = min(ans, a[mx.front()].second - a[mn.front()].second);
                // out <<  a[mx.front()].second << " " << a[mn.front()].second << endl; 
            }
        }

        cout << ans << '\n';
    }
    return 0;
}