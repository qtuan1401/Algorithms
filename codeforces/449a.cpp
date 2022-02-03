#include <bits/stdc++.h>

using namespace std;

long long n, m, k;

inline long long calc(long long x) {
    if (x + 1 <= 0 || (k - x + 1 <= 0))
        return 0;
    //cout << x << " " << k - x << " " << k << endl;
    return n / (x + 1) * (m / (k - x + 1));
}

int main() {
    cin >> n >> m >> k;
    if (n + m - 2 < k) {
        cout << "-1";
        return 0;
    }
    long long temp = k / 2;
    //cout << temp << endl;
    long long res = 1;
    
    cout << max(max(calc(n - 1), calc(k - m + 1)), max(calc(0), calc(k)));
    return 0;
}