#include <bits/stdc++.h>

using namespace std;

string s;

int main() {
    cin >> s;
    if (s.size() == 1) {
        if (s[0] == '4' || s[0] == '8')
            cout << 4;
        else 
            cout << 0;
    } else {
        int num = (s[s.size() - 2] - '0') * 10 + (s[s.size() - 1] - '0');
        if (num % 4 == 0)
            cout << 4;
        else 
            cout << 0;
    }
    return 0;
}