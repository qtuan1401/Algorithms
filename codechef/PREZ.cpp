#include <bits/stdc++.h>

using namespace std;

int n, k;
string s;

bool check(int x) {
    int sum = 0;
    for (int i = x; i >= 0; i--) {
        int num = s[i] - '0';
        num = (num + sum) % 10;
        if (num == 0) continue;
        sum += 10 - num;
        if (sum > k) return false;
    }
    return true;
}

int bs(int l, int r) {
    int ans = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        // cout << l << " " << r << " " << mid << " " << check(mid) << endl;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    return ans;
}

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        cin >> s;
        cout << bs(0, n - 1) + 1 << '\n';
    }
    return 0;
}