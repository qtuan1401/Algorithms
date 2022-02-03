#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;
const int MOD = 1e9 + 7;

long long n, x, y, res;
pair < long long, long long > a[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> x >> y;
    for(int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a, a + n);
    res = (x + y * (a[0].second - a[0].first)) % MOD;
    //cout << res << endl;
    multiset < long long > s;
    s.insert(a[0].second);
    for(int i = 1; i < n; i++) {
        //cout << a[i].first << " * " << a[i].second << endl;
        if (*s.begin() >= a[i].first)
            res = (res + x + y * (a[i].second - a[i].first)) % MOD;
        else {
            multiset < long long > :: iterator it = s.lower_bound(a[i].first);
            it--;
            //cout << (*it) << endl;
            res = (res + min(x, y * (a[i].first - (*it))) + y * (a[i].second - a[i].first)) % MOD;
            s.erase(it);
        }
        s.insert(a[i].second);
    }
    cout << res;
    return 0;
}