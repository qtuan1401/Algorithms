#include <bits/stdc++.h>

using namespace std;

const long long MXN = 2e5 + 10;

map < long long, long long> mp;
long long sz[MXN], x[MXN], l[MXN], c[MXN];
long long n, m;

long long f(long long id) {
    if (mp.count(id))
        return mp[id];
    long long pos = upper_bound(sz, sz + m, id) - sz;
    long long res = sz[pos - 1];
    return mp[id] = f((id - res) % l[pos]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> m;
    long long tot = 0;
    for(long long i = 0 ; i < m; i++) {
        long long type;
        cin >> type;
        if (type == 1) {
            long long x;
            cin >> x;
            mp[tot++] = x;
        } else {
            cin >> l[i] >> c[i];
            tot += l[i] * c[i];
        }
        sz[i] = tot;
    }
    cin >> n;
    for(long long i = 0; i < n; i++) {
        long long x;
        cin >> x;
        x--;
        cout << f(x) << " ";
    }
    return 0;
}