#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    int n;
    cin >> n;
    cin >> s;
    for(int i = 0; i < n; i++) {
        if (s[i] == '0') {
            cout << i + 1;
            return 0;
        }
    }
    cout << n;
    return 0;
}