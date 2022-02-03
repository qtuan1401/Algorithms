#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int a = s[0] - '0', b = s[1] - '0', c = s[2] - '0';
    cout << (a + b + c) * 111; 
    return 0;
}