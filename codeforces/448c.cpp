#include <bits/stdc++.h>

using namespace std;

const int MXN = 5e3 + 10;
const int T = 1e6+6;

int a[MXN], seg[MXN * 4];
int n, lvl;

int rmq(int i, int j) {
    int pos = i;
    //cout << i << " " << j << " " << lvl << endl;
    for(i += lvl, j += lvl; i <= j; ++i >>= 1, --j >>= 1) {
        //cout << i << " " << j << " " << pos << endl;
        if (i & 1) pos = a[pos] > a[seg[i]] ? seg[i] : pos;
        if (~j & 1) pos = a[pos] > a[seg[j]] ? seg[j] : pos;
    }
    return pos;
}

int calc(int l, int r, int h) {
    if (l > r) 
        return 0;
    //cout << l << " " << r << endl;
    int mid = rmq(l, r);
    int mn = a[mid];
    //cout << l << " * " << r << " " << mid << endl;
    return min(r - l + 1, calc(l, mid - 1, mn) + calc(mid + 1, r, mn) + mn - h);
}

int main() {
    //freopen("test.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    a[n] = 2e9;
    lvl = ceil(log2(n));
    lvl = (1 << lvl);
    //cout << lvl;
    for(int i = 0; i < n; i++) seg[i + lvl] = i;
    for(int i = n + lvl; i < lvl * 2; i++) seg[i] = n;
    
    for(int i = lvl - 1; i > 0; i--) 
        seg[i] = a[seg[i * 2]] < a[seg[i * 2 + 1]] ? seg[i * 2] : seg[i * 2 + 1];
    //return 0;
    cout << calc(0, n - 1 , 0);
    
    return 0;
}
