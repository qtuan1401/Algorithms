#include <bits/stdc++.h>

using namespace std;

long long calc(long long x) {
    long long sum = 0;
    for (long long i = 2; i * i * i <= x; i++)
        sum += x / (i * i * i);
    return sum;
}

long long m;

long long bs(long long l, long long r) {
    long long pos = -1;
    while (l <= r) {
        long long mid = (l + r) >> 1;
        long long cnt = calc(mid);
        if (cnt >= m) {
            if (cnt == m) pos = mid;
            r = mid - 1;
        } else
            l = mid + 1;
    }
    return pos;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> m;
    cout << bs(1, 5e16);
    return 0;
}