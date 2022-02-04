#include <bits/stdc++.h>

using namespace std;

typedef pair < int, int > PII;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector < PII > a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i].first >> a[i].second;
        stack < PII > stk;
        stk.push({1, n});
        for (int i = 0; i < n; i++) {
            int l = stk.top().first, r = stk.top().second;
            stk.pop();
            if (l == r) {
                cout << l << " " << r << " " << l << '\n';
                continue;
            }

            int ansR = -1;
            for (int j = 0; j < n; j++) {
                if (a[j].first == l && a[j].second < r)
                    ansR = max(ansR, a[j].second);
            }

            if (ansR != -1) {
                cout << l << " " << r << " " << ansR + 1 << '\n';
                stk.push({l, ansR});
                if (ansR + 2 <= r)
                    stk.push({ansR + 2, r});
            } else {
                int ansL = n + 1;
                for (int j = 0; j < n; j++)
                    if (a[j].second == r && a[j].first > l)
                        ansL = min(ansL, a[j].first);
                cout << l << " " << r << " " << ansL - 1 << '\n';
                stk.push({ansL, r});
                if (ansL - 2 >= l)
                    stk.push({l, ansL - 2});
            }
        }
        cout << '\n';
    }
    return 0;
}