#include <bits/stdc++.h>

using namespace std;

bool check(char c) {
    return (c == 'a' || c == 'e' || c == 'i' ||  c == 'o' || c == 'u' || c == 'y');
}

string s;

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n >> s;
    bool ok = false;
    while (ok == false) {
        ok = true;
        for(int i = 0; i < s.size() - 1; i++)
            if (check(s[i]) && check(s[i + 1])) {
                s.erase(i + 1, 1);
                ok = false;
            }
    }
    cout << s;
    return 0;
}