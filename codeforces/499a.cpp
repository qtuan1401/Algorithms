#include <bits/stdc++.h>

using namespace std;

int n, x;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> x;
    vector < int > l(n), r(n);
    for(int i = 0; i < n; i++)
        cin >> l[i] >> r[i];
    int cur = 1, nxt = 0, res = 0;
    while (cur <= l[n - 1]) {
        if (cur + x <= l[nxt]) {
            cur += x;
        } else {
            res += r[nxt] - l[nxt] + 1 + (l[nxt] - cur);
            cur = r[nxt] + 1;
            nxt++;
        }
    }
    cout << res;
    return 0;
}