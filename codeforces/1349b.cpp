#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector < int > a(n);
        bool check = false;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            check |= (a[i] == k);
        }
        if (check == false) {
            cout << "no\n";
            continue;
        }
        if (n == 1) {
            cout << (a[0] == k ? "yes\n" : "no\n");
            continue;
        }
        bool found = false;
        for(int i = 1; i < n; i++) {
            if (a[i - 1] >= k && a[i] >= k)
                found = true;
            if (i + 1 < n && (a[i - 1] >= k && a[i + 1] >= k))
                found = true;
            if (found)
                break;
        }
        cout << (found == true ? "yes\n" : "no\n");
    }
    return 0;
}