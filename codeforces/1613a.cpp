#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int x1, p1, x2, p2, x, y;
        cin >> x1 >> p1 >> x2 >> p2;
        int cnt1 = 0, cnt2 = 0;
        x = x1; y = x2;
        while (x > 0) {
            cnt1++;
            x /= 10;
        }
        while (y > 0) {
            cnt2++;
            y /= 10;
        }
        
        if (cnt1 + p1 > cnt2 + p2) {
            cout << ">";
          
        } else if (cnt2 + p2 > cnt1 + p1)
            cout << "<";
        else {
            while (cnt1 < cnt2)
                x1 *= 10, cnt1++;
            while (cnt2 < cnt1)
                x2 *= 10, cnt2++;
            if (x1 > x2)
                cout << ">";
            else if (x2 > x1)
                cout << "<";
            else
                cout << "=";
        }
        cout << '\n';
    }
    return 0;
}