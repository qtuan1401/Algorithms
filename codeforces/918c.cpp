#include <bits/stdc++.h>
 
using namespace std;
 
const int MXN = 5e3 + 5;
 
string s;
int res;
int n, f[MXN][MXN];
 
int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> s;
    n = s.size();
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            if (s[j] != ')') {
                if (j == i)
                    f[i][j] = 1;
                else if (s[j] == '(')
                    f[i][j] = f[i][j - 1] + 1;
                else {
                    if (f[i][j - 1] <= 0)
                        f[i][j] = f[i][j - 1] + 1;
                    else
                        f[i][j] = f[i][j - 1] - 1;
                }
            } else if (j > 0)
                f[i][j] = f[i][j - 1]; 
        }
    }
    for(int i = 0; i < n; i++) {    
        int cnt = 0, cntO = 0, l = i, r = n + 1;
        for(int j = i; j < n; j++) {
            bool ok = true;
            if (s[j] != ')') {
                cnt++;
                r = j;
            } else {
                cnt--;
                if (cnt < 0)
                    ok = false;
                l++;
                while (s[l] == ')')
                    l++;
            }
            if (ok == false)
                break;
            cout << i << " " << j << " " << l << " " << r << " " << f[l][r] << " " << ok << endl;
            if (cnt == 0)
                res++;
            else 
                res += (f[l][r] == 0 && ok);
        }
    }
    cout << res;
    return 0;
}