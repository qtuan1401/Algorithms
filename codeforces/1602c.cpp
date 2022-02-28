#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector < int > cnt(30, 0);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            for (int i = 0; i < 30; i++)
                cnt[i] += (x >> i) & 1;
        }

        int gcd = 0;
        for (int i = 0; i < 30; i++)
            gcd = __gcd(gcd,cnt[i]);
        // cout << "*" << gcd << endl;
        if (gcd == 0) {
            for (int i = 0; i < n; i++)
                cout << i + 1 << " ";
            cout << '\n';
            continue;
        }
        
        vector < int > ans;
        for (int i = 1; i * i <= gcd; i++) {
            if (gcd % i == 0) {
                ans.push_back(i);
                if (i != gcd / i)
                    ans.push_back(gcd / i);
            }
        }

        sort(ans.begin(), ans.end());
        for (int & val: ans) cout << val << " ";
        cout << '\n';
    }
    return 0;
}