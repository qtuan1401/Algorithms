#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector < int > a(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        for (int i = 0; i < n; i++)
            if (a[i] < b[i]) swap(a[i], b[i]);
        int mxA = *max_element(a.begin(), a.end());
        int mxB = *max_element(b.begin(), b.end());
        cout << mxA * mxB << '\n';
    }
    return 0;
}