#include <bits/stdc++.h>

using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    while (tests--) {
        int n;
        cin >> n;
        vector < int > a(n + 1);

        for (int i = 0; i < n; i++) cin >> a[i];

        stack < int > stk;
        long long ans = 0;
        a[n] = n + 2;
        for (int i = 0; i <= n; i++) {
            if (a[i] == 1) {
                stk.push(i);
                continue;
            }
            // if (stk.size()) cout << stk.size() << " " << stk.top() << " ** " << a[stk.top()] << endl;
            while (stk.size() && a[stk.top()] + 1 != a[i]) {
                int p = stk.top();
                while (a[p] != 1) {
                    stk.pop();
                    p = stk.top();
                }
                
                ans += i - p;
                stk.pop();
            }
            // cout << i << " * " << stk.size() << endl;
                
            if (stk.size() && a[stk.top()] + 1 == a[i]) {
                stk.push(i);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}