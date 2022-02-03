#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        int l = 0, r = 0, marked = 0;
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (marked == 0 && x >= i)
                l = i;
            else
                marked = 1;
            if (n - i - 1 > x)
                r = i + 1;
        }
        if (l >= r)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}