#include <bits/stdc++.h>

using namespace std;

const string c = "hello";

int main() {
    ios_base::sync_with_stdio(0);
    int cnt = 0;
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++) {
        cnt += (s[i] == c[cnt]);
        if (cnt == 5) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}