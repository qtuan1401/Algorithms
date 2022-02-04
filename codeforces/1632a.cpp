#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n; 
        string s;
        cin >> n;
        cin >> s;
        if (n >= 3) {
            cout << "NO\n";
            continue;
        }

        if (n == 1) {
            cout << "YES\n";
            continue;
        } 

        if (s[0] == s[1]) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}