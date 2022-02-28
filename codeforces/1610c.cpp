#include <bits/stdc++.h>

using namespace std;

vector < int > a, b;

bool check(int x) {
    int cnt = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] >= x - 1 - cnt && b[i] >= cnt) cnt++;
    }
    return cnt >= x;
}

int bs(int l, int r) {
    int ans = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        a.resize(n); b.resize(n);
        for (int i = 0; i < n; i++)
            cin >> a[i] >> b[i];
        
        cout << bs(0, n) << '\n';
    }
    return 0;
}