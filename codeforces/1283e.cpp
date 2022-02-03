#include <bits/stdc++.h>

using namespace std;

const int md = 2e5 + 10;

int a[md], cnt[md];
int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i], cnt[a[i]]++;

    int res = 0;
    for(int i = 1; i <= n; i++) {
        if (!cnt[i]) continue;
        res++; i += 2;
    }
    cout << res << " ";
    for(int i = 1; i <= n; i++) {
        if (cnt[i] == 0)
            continue;
        if (cnt[i - 1] == 0) {
           cnt[i]--;
           cnt[i - 1]++; 
        }
        if (cnt[i] > 1) {
            cnt[i]--;
            cnt[i + 1]++;
        }
    }
    res = 0;
    for(int i = 0; i <= n + 1; i++)
        res += (cnt[i] > 0);
    cout << res;
    return 0;
}