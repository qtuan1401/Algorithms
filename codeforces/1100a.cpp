#include <bits/stdc++.h>

using namespace std;

int cnt[2];

int main() {
    ios_base::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    vector < int > a(n + 1);
    
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[0] += (a[i] == 1);
        cnt[1] += (a[i] == -1);
    }
    int res = 0;
    for(int b = 1; b <= 100; b++) {
        int cnt1 = 0, cnt2 = 0;
        //cout << b << endl;
        for(int i = -100; i <= 100; i++) {
            int p = b + i * k;
            //cout << b << endl;
            if (1 <= p && p <= n) {
                //cout << p << " ";
                cnt1 += a[p] == 1;
                cnt2 += a[p] == -1;
            }
        }
        //cout << endl;
        //cout << cnt[0] << " " << cnt1 << " " << cnt[1] << " " << cnt2 << endl;
        res = max(res, abs((cnt[0] - cnt1) - (cnt[1] - cnt2)));
        //cout << "*" << res << endl;
    }
    cout << res;
    return 0;
}