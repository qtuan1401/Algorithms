#include <bits/stdc++.h>
 
using namespace std;
 
const int MAXN = 1e5 + 10;
 
int n;
int a[MAXN];
long long t, res;
 
int main() {
    //freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n >> t;
    for(int i = 0; i < n; i++)
        cin >> a[i];      
    sort(a, a + n);
    int l = 0, r = n - 1;
    long long cntL = 1, cntR = 1;
    while (l < r && t > 0) {
        long long diff1 = a[l + 1] - a[l];
        long long diff2 = a[r] - a[r - 1];
        if (cntL <= cntR) {
            if (t < diff1 * cntL) {
                cout << a[r] - a[l] - t / cntL;
                return 0;
            } 
            t -= diff1 * cntL;
            cntL++;
            l++;
        } else {
            if (t < diff2 * cntR) {
                cout << a[r] - a[l] - t / cntR;
                return 0;
            }
            t -= diff2 * cntR;
            cntR++;
            r--; 
        }
    }
    cout << 0;
    return 0;
}