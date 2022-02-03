#include <bits/stdc++.h>

using namespace std;

long long n, st, len, pos, pre;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    st = 1;
    for(long long i = 10, j = 1; ; i *= 10, j++) {
        len = j;
        long long cnt = 1ll * (i - 1 - st + 1) * j; 
        if (n <= cnt) 
            break;
        st = i;
        n -= cnt;
    }
    long long num = st + n / len - 1 + (n % len != 0);
    int pos = n % len;
    if (pos == 0)
        pos = len;
    int p = len;
    while (num > 0) {
        if (p == pos)
            cout << num % 10;
        num /= 10; p--;
    }
    return 0;
}