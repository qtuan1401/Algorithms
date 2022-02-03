#include <bits/stdc++.h>

using namespace std;

int main() {
    int res = 0, n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        res += (a + b + c > 1);
    }
    cout << res;
    return 0;
}