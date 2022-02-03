#include <bits/stdc++.h>

using namespace std;

int w, h, d1, u1, u2, d2;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> w >> h;
    cin >> u1 >> d1 >> u2 >> d2;
    //cout << w << " " << h;
    for(int i = h; i >= 0; i--) {
        w += i;
        if (i == d1)
            w -= u1;
        if (i == d2)
            w -= u2;
        w = max(0, w);
    }
    cout << w;
    return 0;
}