#include <bits/stdc++.h>

using namespace std;

string s;

int main() {
    int n;
    cin >> n >> s;
    long long cnt = 0;
    for(int i = 0, j = 1; i < n; ) {
        while (s[i] == s[j])
            j++;
        if (j <  n)
            cnt -= j - i;
        if (i > 0)
            cnt -= j - i - 1;
        i = j;
    }
    cout << 1ll * n * (n - 1) / 2 + cnt;
    return 0;
}