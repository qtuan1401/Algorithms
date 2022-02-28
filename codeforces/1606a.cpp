#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        
        int n = s.size();
        for (int j = -1; j < n; j++) {
            if (j >= 0) {
                if (s[j] == 'a') s[j] = 'b';
                else if (s[j] == 'b') s[j] = 'a';
            }

            int cntAB = 0, cntBA = 0;
            for (int i = 0; i + 1 < n; i++) {
                cntAB += (s[i] == 'a' && s[i + 1] == 'b');
                cntBA += (s[i] == 'b' && s[i + 1] == 'a');
            }

            // cout << s << " " << j << " " << cntAB << " " << cntBA << endl;
            if (cntAB == cntBA) {
                cout << s << '\n';
                break;
            }
            
            if (j >= 0) {
                if (s[j] == 'a') s[j] = 'b';
                else if (s[j] == 'b') s[j] = 'a';
            }
        }
    }
    return 0;
}