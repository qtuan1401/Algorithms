#include <bits/stdc++.h>

using namespace std;

const int MXN = 55;

int p, q, l, r;
int a[MXN], b[MXN], c[MXN], d[MXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin >> p >> q >> l >> r;
    for(int i = 0; i < p; i++)
        cin >> a[i] >> b[i];
    for(int i = 0; i < q; i++)
        cin >> c[i] >> d[i];
    int res = 0;
    for(int k = l; k <= r; k++) {
        for(int cnt = 0, i = 0; i < p && !cnt; i++)
            for(int j = 0; j < q && !cnt; j++) {
                //cout << a[i] << " " << b[i] << " " << d[j] << " " << c[j] << " " << cnt << " " << a[i] << " " << b[i] << " " << c[j] + k << " " << d[j] + k << " " << (a[i]<=d[j]+k&&b[i]>=c[j]+k) << endl;
                if (a[i] <= d[j] + k && b[i] >= c[j] + k)
                    cnt = ++res;
            }
    }
                
    cout << res;
    return 0;
}