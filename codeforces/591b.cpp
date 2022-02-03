#include <bits/stdc++.h>

using namespace std;

int n, m;
string s;
char c[] = {"abcdefghijklmnopqrstuvwxyz"};

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> s;
    while (m--) {
        char x, y;
        cin >> x >> y;
        for(int i = 0; i < 26; i++)
            if (c[i] == x)
                c[i] = y;
            else if (c[i] == y)
                c[i] = x;
    }
    for(int i = 0; i < n; i++)
        cout << c[s[i] - 'a'];
}