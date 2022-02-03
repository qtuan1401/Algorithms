#include <bits/stdc++.h>

using namespace std;

long long n;

int main() {
    cin >> n;
    if (18 * 2 >= n) {
        for(int i = 0; i < n / 2; i++)
            cout << 8;
        if (n & 1) 
            cout << 6;
    } else 
        cout << -1;
    return 0;
}