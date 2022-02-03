#include <bits/stdc++.h>

using namespace std;

string s;
vector < int > ansL, ansR;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> s;
    int l = 0, r = s.size() - 1;
    int len = s.size() / 2, cnt = 0;
    while (cnt < len && l <= r) {
        if (s[l] == s[r]) {
            ansL.push_back(l);
            if (l != r) ansR.push_back(r);
            l++;
            r--;
        } else if (s[l] == s[r - 1]) 
            r--;
        else if (s[l + 1] == s[r])
            l++;
        else {
            l++;
            r--;
        }
    }
    for(int i = 0; i < ansL.size(); i++)
        cout << s[ansL[i]];
    for(int i = (int)ansR.size() - 1; i >= 0; i--)
        cout << s[ansR[i]]; 
    return 0;
}