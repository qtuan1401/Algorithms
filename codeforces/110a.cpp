#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n, cnt = 0;
    ios_base::sync_with_stdio(0);
    cin >> n;
    while (n) {
        cnt += (n % 10 == 4 || n % 10 == 7);
        n /= 10;
    }
    if (cnt == 0) {
        cout << "NO";
        return 0;
    }
    while (cnt) {
        if (cnt % 10 != 4 && cnt % 10 != 7) {
            cout << "NO";
            return 0;
        }
        cnt /= 10;
    }
    cout << "YES";
    return 0;
}