#include <bits/stdc++.h>

using namespace std;

const int MXN = 1e5 + 10;

int n;
int a[MXN], l[MXN], r[MXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    l[0] = 1;
    for(int i = 1; i < n; i++)
        if (a[i - 1] < a[i])
            l[i] = l[i - 1] + 1;
        else
            l[i] = 1;
    r[n - 1] = 1;
    for(int i = n - 2; i >= 0; i--) 
        if (a[i] < a[i + 1])
            r[i] = r[i + 1] + 1;
        else
            r[i] = 1;
    int res = 0;
    for(int i = 0; i < n; i++) {
        int num1 = -2e9, num2 = 2e9;
        if (i - 1 >= 0)
            num1 = a[i - 1];
        if (i + 1 < n)
            num2 = a[i + 1];
        if (num1 + 2 <= num2) {
            //cout << i << " " << (i - 1 >= 0 ? l[i - 1] : 0) + r[i + 1] + 1 << " " << l[i - 1] << " " << r[i + 1] << endl;
            res = max(res, (i - 1 >= 0 ? l[i - 1] : 0) + r[i + 1] + 1);
        } else {
            res = max(res, max((i - 1 >= 0 ? l[i - 1] : 0) + 1, r[i + 1] + 1));
        }
    }
    cout << res;
    return 0;
}