#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int n = s.size();
        int mx = 0, p = 0;
        for (int i = 1; i < n; i++) {
            int x = s[i - 1] - '0', y = s[i] - '0';
            if (x + y >= 10) {
                p = i;
                mx = x + y;
            }
        }
        if (mx != 0) {
            for (int i = 0; i < n; i++) {
                if (i != p && i != p - 1)
                    cout << s[i];
                else if (i == p)
                    cout << mx;
            }
        } else {
            int x = s[0] - '0', y = s[1] - '0';
            cout << x + y;
            for (int i = 2; i < n; i++)
                cout << s[i];
        }
        cout << '\n';
    }
    
    return 0;
}