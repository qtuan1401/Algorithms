#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int p = 0;
        for (int i = 0; i < s.size(); i++)
            if (s[i] < s[p]) p = i;
        cout << s[p] << " ";
        for (int i = 0; i < s.size(); i++)
            if (i != p) cout << s[i];
        cout << '\n';
    }
    return 0;
}