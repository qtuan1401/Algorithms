#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;
const int MAXV = 2e6 + 10;

int n, res, mx;
int a[MAXN], preNum[MAXV], marked[MAXV];

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        preNum[a[i] + 1] = a[i];
        mx = max(mx, a[i]);
    }
    mx *= 2;
    for(int i = 1; i <= mx; i++)
        if (preNum[i] == 0)
            preNum[i] = preNum[i - 1];
    for(int i = 0; i < n; i++) {
        if (marked[a[i]])
            continue;
        marked[a[i]] = true;
        for(int j = a[i] * 2; j <= mx; j+= a[i]) {
            res = max(res, preNum[j] - j + a[i]);
        }
    }
    cout << res;
    return 0;
}