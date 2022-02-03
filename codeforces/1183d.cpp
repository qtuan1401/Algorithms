#include <bits/stdc++.h>

using namespace std;

const int MXN = 2e5 + 10;

int cnt[MXN];

int main(){
    ios_base::sync_with_stdio(0);
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        for(int i = 0; i <= n; i++)
            cnt[i] = 0;
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            cnt[x]++;
        }
        //continue;
        sort(cnt, cnt + n + 1);
        int res = 0, remain = cnt[n];
        for(int i = n; i > 0 && remain > 0; i--) {
            remain = min(remain, cnt[i]);
            res += remain--;
        }
        cout << res << '\n';
    }
    return 0;
}