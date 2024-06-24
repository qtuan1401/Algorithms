#include <bits/stdc++.h>

using namespace std;

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
        vector < pii > a(n);
        for (int i = 0; i < n; i++) cin >> a[i].first;
        for (int i = 0; i < n; i++) cin >> a[i].second;

        sort(a.begin(), a.end());

        for (int i = 0; i < n; i++) cout << a[i].first << " ";
        cout <<  '\n';
        for (int i = 0; i < n; i++) cout << a[i].second << " ";
        cout <<  '\n'; 
    }
    return 0;
}