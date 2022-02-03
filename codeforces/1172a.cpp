#include <bits/stdc++.h>

using namespace std;

const int md = 2e5 + 10;

int n, res;
int a[md], b[md], p[md];

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        p[a[i]] = 0;
    }
    for(int i = 1; i <= n; i++) {
        cin >> b[i];
        p[b[i]] = i;
    }
    if (p[1]) {
        int i = 0;
        for(i = 2; i <= n && p[1] == p[i] - i + 1; i++);
        //cout << i << endl;
        if (p[i - 1] == n) {
            int j = 0;
            for(j = i; j <= n && p[j] <= j - i; j++);
            if (j > n) {
                cout << n - i + 1;
                return 0;
            }
        }
    }
    //cout << "*";
    int res = 0;
    for(int i = 1; i <= n; i++)
        res = max(res, p[i] - i + 1 + n);

    cout << res;
    return 0;
}