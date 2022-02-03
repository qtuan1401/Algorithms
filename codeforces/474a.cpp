#include <bits/stdc++.h>

using namespace std;

string c = "qwertyuiopasdfghjkl;zxcvbnm,./";

int main() {
    ios_base::sync_with_stdio(0);
    char x;
    string s;
    cin >> x >> s;
    for(int i = 0; i < s.size(); i++)
        cout << c[c.find(s[i]) - (x == 'R') + (x == 'L')];
    
}