#include <bits/stdc++.h>

using namespace std;

const int MXN = 5e5 + 10;

int n;
string s[MXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> s[i];
    for(int i = n - 2; i >= 0; i--) {
        if (s[i + 1] < s[i])
            for(int j = 0; j < s[i].size(); j++)
                if (s[i + 1][j] < s[i][j])
                    s[i].resize(j);
    }
    for(int i = 0; i < n; i++)
        cout << s[i] << '\n';
    return 0;   
}