#include <bits/stdc++.h>

using namespace std;

int a[500005];

int main() {
    ios_base::sync_with_stdio(0);
    int n, k, b;
    cin >> n >> k >> b;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    long long sum = 0;
    multiset < int > s;
    int res = n - 1;
    for (int i = n - 2; i >= 0; i--) {
        sum += a[i];
        // cout << sum << endl;
        s.insert(a[i]);
        if (sum > b) {
            res = i;
        }
        if (s.size() >= k) {
            sum -= *s.begin();
            s.erase(s.begin());
        }
    }
    cout << res + 1;
    return 0;
}