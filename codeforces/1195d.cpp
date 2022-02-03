#include <bits/stdc++.h>

using namespace std;

const unsigned long long mod = 998244353;
const int md = 1e5 + 10;

unsigned long long p[md], a[md], d[md], digit[md], c[md], sum[md];
unsigned long long res = 0;
int n = 0;

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n;
    p[1] = 1;
    for(int i = 2; i <= 20; i++)
        p[i] = p[i - 1] * 10;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++) {
        int x = a[i], cnt = 0;
        while (x > 0) {
            cnt++;
            x /= 10;
        }
        d[cnt]++;
        c[i] = cnt;
    }
    for(int i = 10; i >= 1; i--)
        sum[i] = sum[i + 1] + d[i];
    for(int num = 1; num <= n; num++) {
        int x = a[num], cnt = 0;
        for(int i = 1; i <= 10; i++) {
            digit[i] = x % 10;
            x /= 10;
        }
        /*for(int i = 1; i <= 10; i++)
            cout << digit[i] << " ";
        cout << endl;*/
        for(int i = 1, j = 1; i <= 10 && j <= 20; i++, j += 2) {
            if (d[i] > 0 && c[num] > i) {
            //    cout << a[num] / p[i + 1] * p[i * 2 + 1] * d[i] * 2 << " * " << p[i + 1] <<" * " << p[i * 2 + 1] << " " << i << endl;
                res = (res + (((a[num] / p[i + 1]) % mod * p[i * 2 + 1]) % mod * d[i] * 2) % mod) % mod; 
            //    cout << res << " | " << i << endl;
            //    cout << res <<  " | " << i << endl;
            }          
            /*if (i <= c[num])
                cout << res <<" " <<digit[i] * p[j] << " " << digit[i] * p[j + 1] << " " << sum[c[num]] << endl;*/
            res = (res + ((digit[i] * p[j]) % mod * sum[i]) % mod) % mod; //0x
            res = (res + ((digit[i] * p[j + 1]) % mod * sum[i]) % mod) % mod; //y0
            //if (i <= c[num]) cout << res << endl;
        }
    }
    cout << res;
    return 0;
}