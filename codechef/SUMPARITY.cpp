#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, a;
        cin >> n >> a;
        if (a % 2 == 0) {
            if (n == 1)
                cout << "Even";
            else
                cout << "Impossible";
        } else {
            if (n % 2 == 0)
                cout << "Even";
            else
                cout << "Odd";
        }
        cout << '\n';
    }
    return 0;
}