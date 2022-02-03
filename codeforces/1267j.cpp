#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e6 + 10;

int n;
int a[MAXN], c[MAXN];

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for(int i = 0; i < n; i++) 
            cin >> a[i];
        //continue;
        sort(a, a + n);
        int len = 0;
        c[len] = 1;
        for(int i = 1; i < n; i++)
            if (a[i] == a[i - 1])
                c[len]++;
            else {
                c[++len] = 1;
            }
        len++;
        sort(c, c + len);
        //for(int i = 0; i < len; i++)
        //    cout << c[i] << " ";
        int ans = n;
        for(int s = 1; s <= c[0] + 1; s++) {
            bool ok = true;
            int sum = 0;
            for(int i = 0; i < len; i++) {
                int x = c[i] / s + (c[i] % s > 0);
                if (x * (s - 1) > c[i])
                    ok = false;
                sum += x;
            }
            if (ok)
                ans = min(ans, sum);
        }
        cout << ans << '\n';
    }
    return 0;
}