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
        string a, b;
        cin >> a >> b;
        int n = a.size();
        int l = 0;
        while (l < n && a[l] == b[l]) l++;
        if (a[l] < b[l]) swap(a[l], b[l]);
        l++;
        for (int i = l; i < n; i++) {
            if (a[i] > b[i]) swap(a[i], b[i]);
        }

        cout << a << '\n' << b << '\n';
    }
    return 0;
}