#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    long long originSum = 1ll * n * (n + 1) / 2 * 4;
    long long sum = 0;
    for (int i = 0; i + 1 < 4 * n; i++) {
        int x;
        cin >> x;
        sum += x;
    }
    cout << originSum - sum;
    return 0;
}