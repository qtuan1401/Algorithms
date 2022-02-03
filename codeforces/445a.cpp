#include <bits/stdc++.h>

using namespace std;

int n, m;
string s[105];

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> s[i];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            if (s[i][j] == '-')
                cout << s[i][j];
            else {
                if ((i + j) & 1)
                    cout << 'W';
                else 
                    cout << 'B';
            }
        cout << '\n';
    }
    return 0;
}