#include <bits/stdc++.h>

using namespace std;

int calc(string x, string y) {
    int n = x.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += abs(x[i] - y[i]);
    }
    return ans;
}

string modify(string x, int p, int val) {
    string ans = x;
    ans[p] += val;
    for (int i = p + 1; i < ans.size(); i++) {
        if (val == 1) ans[i] = '0';
        else ans[i] = '9';
    }
    return ans;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests;
    cin >> tests;
    while (tests--) {
        string x, y;
        cin >> x >> y;
        
        while (x.size() < y.size()) x = "0" + x;
        
        int i = 0, n = x.size();
        int ans = calc(x, y);
        while (i < n && x[i] == y[i]) i++;
        if (i == n) {
            cout << "0\n";
            continue;
        }

        int l = x[i] - '0';
        int r = y[i] - '0';
        cout << 9 * (n - 1 - i) + r - l << '\n';
    }
    return 0;
}