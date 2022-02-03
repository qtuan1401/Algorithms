#include <bits/stdc++.h>

using namespace std;

string s;

int main() {
    //freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> s;
    int diff = 0;
    for(int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == '0')
            diff++;
        else if (diff <= 0)
            s[i] = '0';
        else diff--;
    }
    cout << s;
    return 0;
}