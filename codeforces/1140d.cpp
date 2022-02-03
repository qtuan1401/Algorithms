#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
    cin >> n;
    long long res = 0;
    for(int i = 2; i < n; i++) {
        res += 1ll * i * (i + 1);
    }
    cout << res;
}