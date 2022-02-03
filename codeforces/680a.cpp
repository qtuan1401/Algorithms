#include <bits/stdc++.h>
using namespace std;

int cnt[105];

int main() {
    ios_base::sync_with_stdio(0);
    int sum = 0, mx = 0;
    for(int i = 0; i < 5; i++) {
        int x;
        cin >> x;
        sum += x;
        if (++cnt[x] > 1)
            mx = max(mx, x * min(3, cnt[x]));
    }
    cout << sum - mx;
    return 0;
}