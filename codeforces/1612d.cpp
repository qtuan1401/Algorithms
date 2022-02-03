#include <bits/stdc++.h>

using namespace std;

bool check(long long a, long long b, long long x) {
    if (a == x || b == x)
        return true;
    if (a < b)
        swap(a, b);
    if (b > a - b)
        b = a - b;
    if (x > max(a, b) || a == 0 || b == 0)
        return false;
    long long cnt = max((a - max(x, b)) / (b * 2), 1ll);
    return check(a - b * cnt, b, x);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        long long a, b, x;
        cin >> a >> b >> x;
        if (check(a, b, x))
            cout << "YES";
        else
            cout << "NO";
        cout << '\n';
    }
    return 0;
}