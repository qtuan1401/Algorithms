#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    getline(cin, s);
    set < char > cnt;
    for(int i = 0; i < s.size(); i++)
        if (isalpha(s[i])) 
            cnt.insert(s[i]);
    cout << cnt.size();
    return 0;
}