#include <bits/stdc++.h>

using namespace std;

int x, cnt1, cnt2, n;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> x;
        cnt1 += (x == 1);
        cnt2 += (x == 2);
    }
    if (!cnt1 || !cnt2) {
        int x;
        if (cnt1)
            x = 1;
        else x = 2;
        for(int i = 1; i <= n; i++) 
            cout << x << " ";
    } else {
        cout << 2 << " " << 1 << " ";
        for(int i = 1; i < cnt2; i++)
            cout << 2 << " ";
        for(int i = 1; i < cnt1; i++)
            cout << 1 << " ";
    }
    return 0;
}