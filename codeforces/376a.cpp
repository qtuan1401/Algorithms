#include <bits/stdc++.h>
     
using namespace std;

string s;
     
int main() {
    cin >> s;
    long long diff = 0;
    int p = 0;
    for( ; s[p] != '^'; p++);
    for(int i = 0; i < s.size(); i++) {
        if (s[i] == '=' || s[i] == '^')
            continue;
        diff += (1ll * (s[i] - '0') * (p - i));
    }
    if (diff > 0) 
        cout << "left";
    else if (diff < 0)
        cout << "right";
    else
        cout << "balance";
        return 0;
}