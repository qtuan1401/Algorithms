#include <bits/stdc++.h>
using namespace std;

string s;
int k;

int main() {
    ios_base::sync_with_stdio(0);
    
    cin >> s >> k;
    int n = s.size();

    if (k >= n) {
        cout << ((n + k) / 2) * 2;
        return 0;
    }
    int res = 0;
    for(int i = 0;i < n; i++) {
        for(int j = 1; j < 200; j++)  {
            if (i + 2 * j > n + k)
                break;
            bool ok = true;
            for(int k = i; k < i + j && k + j < n; k++)
                if (s[k] != s[k + j]) {
                    ok = false; 
                    break;
                }
            if (ok)
                res = max(2 * j, res);
        }
    }
    cout << res;
}