#include <bits/stdc++.h>

using namespace std;

long long k, n, m;

long long calc(long long x) {
    long long cnt = 0;
    for(int i = 1; i <= n; i++) 
        cnt += min(x / i, m);
    return cnt;
}

long long bs(long long l, long long r) {
    long long pos = 0;
    while (l <= r) {
        long long mid = (l + r) / 2;
        if (calc(mid) >= k) {
            pos = mid;
            r = mid - 1;
        } else
            l = mid + 1;
    }
    return pos;
}

int main() {
    cin >> n >> m >> k;
    cout << bs(1, n * m);
    return 0;
}