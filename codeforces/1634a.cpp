#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        if (k == 0) {
            cout << "1\n";
            continue;
        }
        string ss = s;
        reverse(ss.begin(), ss.end());
        // cout << s + ss << " " << ss + s << endl;
        if (s + ss != ss + s) {
            cout << "2\n";    
        } else cout << "1\n";
        
    }
    return 0;
}