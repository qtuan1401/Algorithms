#include <bits/stdc++.h>

using namespace std;

string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> s;
    int k;
    cin >> k;
    int n = s.size();
    if (n % k != 0) {
        cout << "NO";
        return 0;
    }
    k = n / k;
    for(int i = 0; i < n; i += k) {
        bool ok = true;
        for(int j = 0; j < k / 2; j++)
            if (s[i + j] != s[i + k - j - 1])
                ok = false;
        if (ok == false) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}