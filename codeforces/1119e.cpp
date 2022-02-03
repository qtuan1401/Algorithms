#include <bits/stdc++.h>

using namespace std;

const int MXN = 3e5 + 10;

int n;
long long a[MXN];
stack < int > stk;
long long res = 0;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int pos = 0;
    res = a[0] / 3;
    a[0] %= 3;
    for(int i = 1; i < n; i++) {
        while (a[i] / 2 > a[pos] && pos < i) {
            res += a[pos];
            //cout << pos << " * "  << i << " " << res << endl;
            a[i] -= a[pos] * 2;
            a[pos] = 0;
            pos++;
        }
        //cout << i << " " << pos << endl;
        if (a[i] / 2 > 0 && pos < i) {
            res += a[i] / 2;
            a[pos] -= a[i] / 2;
            a[i] %= 2;
        } else if (pos == i) {
            res += a[i] / 3;
            a[i] %= 3;
        }
    }
    
    cout << res;
    return 0;
}