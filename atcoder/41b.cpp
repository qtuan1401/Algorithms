#include <bits/stdc++.h>

using namespace std;

const int md = 1e5 + 10;

long long a[md];
long long n, m, v, p;

bool check(int x) {
    if (x < p)
        return true;
    if (a[x] + m < a[p - 1])
        return false;
    long long sum = 0;
    for(int i = 0; i < n; i++) {
        if (i < p - 1)
            sum += m;
        else if (i == x)
            sum += m;
        else if (i > x)
            sum += m;
        else {
            sum += a[x] + m - a[i];
        }
    }
    return sum >= m * v;
}

int bs(int l, int r) {
    while (r - l > 1) {
        int mid = (l + r) >> 1;
        if (check(mid))
            l = mid;
        else r = mid;
    }
    return l + 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> v >> p;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    reverse(a, a + n);
    cout << bs(-1, n);
    return 0;
}