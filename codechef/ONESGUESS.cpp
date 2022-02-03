#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int cur = 1;
    for (int i = 0; i < n; i++) {
        cout << cur << endl;
        int x;
        cin >> x;
        cur += (x == 1);
    }
    return 0;
}