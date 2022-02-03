#include <bits/stdc++.h>

using namespace std;

int cnt[10];
int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]--;
    }

    int res = 0;
    for(int i = 1; i <= 5; i++) {
        cnt[i] = abs(cnt[i]);
        if (cnt[i] & 1) {
            cout << "-1";
            return 0;
        } 
        res += cnt[i] / 2;
    }

    cout << res / 2;
    return 0;
}