#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    while (tests--) {
        long long a, b;
        cin >> a >> b;
        cout << a / b + (a % b > 0);
    }
    return 0;
}