#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector < int > a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[i] -= x;
    }
    sort(a.begin(), a.end());
    long long res = 0;
    for(int i = n - 1; i >= 1; i--) {
        if (a[n - i - 1] + a[n - 1] > 0) {
            res += i;
            n--;
        }
    }
    cout << res;
}