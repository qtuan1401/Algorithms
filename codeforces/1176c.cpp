#include <bits/stdc++.h>

using namespace std;

int pos[100], cnt[6];

int main() {
    int n;
    cin >> n;
    pos[4] = 0; pos[8] = 1; pos[15] = 2; pos[16] = 3; pos[23] = 4; pos[42] = 5;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (pos[x] == 0)
            cnt[pos[x]]++;
        else if (cnt[pos[x] - 1] > 0) {
            cnt[pos[x]]++;
            cnt[pos[x] - 1]--;
        }
    }
    cout << n - cnt[5] * 6;
    return 0;
}