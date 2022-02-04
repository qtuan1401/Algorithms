#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int cnt0 = 0, cnt1 = 0;
        for (int i = 0; i < s.size(); i++) {
            cnt0 += s[i] == '0';
            cnt1 += s[i] == '1';
        }
        cout << min(cnt0, cnt1) - (cnt0 == cnt1) << '\n';
    }
    return 0;
}