#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> T;
    while (T--) {
        long long n, res = 0;
        cin >> n;
        while (true) {
            if (n % 2 == 0)
                n /= 2;
            else if (n % 3 == 0)
                n = n * 2 / 3;
            else if (n % 5 == 0)
                n = n * 4 / 5;
            else
                break;
            res++;
        }
        if (n > 1)
            cout << "-1\n";
        else
            cout << res << '\n';
    }
}