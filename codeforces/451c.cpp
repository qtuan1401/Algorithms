#include<bits/stdc++.h>

using namespace std;

long long n, k;

inline bool check(long long a, long long b) {
    long long c = k - a - b * 2;
    if (c < 0 || c % 3 ) 
        return 0;
    return (n / 3 >= a + b + c /3);
}

int main() {
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        long long d1, d2;
        cin >> n >> k >> d1 >> d2;
        if (n % 3) {
            cout << "no\n";
            continue;
        } 
        if (check(d1, d2) || check(d2, d1) || check(abs(d1 - d2), min(d1, d2)) || check(min(d1, d2), abs(d1 - d2)))
            cout << "yes\n";
        else
            cout << "no\n";
    }
    return 0;
}