#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector < int > a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        if (n == 1) {
            cout << "YES\n";
            continue;
        }
        if (a[n - 1] == 1) {
            cout << "NO\n";
            continue;
        }

        vector < int > num;
        int l = 0;
        bool ok = true;
        int mx = n;
        vector < bool > marked(n + 1, 0);
        while (a[l] > a[n - 1]) {
            // cerr << mx << endl;
            // cerr <<"*" << a[l] << endl;
            for (int i = l; i < n - 1; i++)
                if (a[i] <= mx) {
                    num.push_back(a[i]);
                    if (a[i] == mx) break;
                }
            vector < int > origin = num;
            sort(num.begin(), num.end());
            for (int i = 0; i < num.size(); i++)
                marked[num[i]] = true;
            if (num.size() == 0 || num[0] < a[n - 1]) break;
            // cerr << num.back() << " * " << l << " " << num[0] << " " << a[n - 1] << endl;
            ok = false;
            for (int i = (int)num.size() - 1; i >= 0; i--) {
                if (mx != num[i] && !marked[mx])
                    break;
                else {
                    mx--;
                }
            }
            int mn = num[0];
            // cerr << mn << " " << mx << endl;
            ok = mn < mx;
            num.clear();
            num.push_back(mn);
            marked[mn] = false;
            if (ok) {
                l += num.size();
            } else break;
            // cerr << mx << " " << l << " " << a[l] << endl;
        }
        if (!ok) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
    return 0;
}