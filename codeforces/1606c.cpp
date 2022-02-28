#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e15;

vector < long long > f(19);
long long res = 0;

void solve(long long k) {
    if (k <= 0) return ;
    long long digit = 1;
    long long sum = 0;
    // cout << k << endl;
    bool found = false;
    for (int i = 0; i < 19; i++) {
        // cout << i << " " << sum << endl;
        for (int j = 1; j <= 9; j++) {
            if (sum + f[i] * j >= k) {
                // cout << res << " * " << i << " * " << sum + f[i] * j << " " << k - f[i] * j << endl;
                res += digit * j;
                solve(k - f[i] * j);
                found = true;
                break;
            }
        } 
        if (found) break;
        sum += f[i] * 9;
        digit *= 10;
    }
}

int main() {
    freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        long long n, k;
        cin >> n >> k;
        vector < int > a(n);
        f.clear();
        f.resize(19, INF);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            f[a[i]] = 1;
        }
        res = 0;
        long long sum = 9;
        for (int i = 1; i < 19; i++) {
            f[i] = min(f[i], min(f[i - 1] * 10, sum + 1));
            sum += f[i] * 9; 
            // cout << f[i] <<  " " << sum << endl;
        }

        // for (int i = 0; i < 19; i++)
        //     cout << f[i] << " ";
        // cout << endl;

        solve(k + 1);

        cout << res << '\n';
    }
    return 0;
}