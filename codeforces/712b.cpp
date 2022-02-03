#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    string s;
    cin >> s;
    //cout << s << endl;
    int cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < s.size(); i++) {
        if (s[i] == 'L')
            cnt1++;
        else if (s[i] == 'R')
            cnt1--;
        else if (s[i] == 'U')
            cnt2++;
        else 
            cnt2--;
    }
    int sum = abs(cnt1) + abs(cnt2);
    if (sum & 1)
        cout << "-1";
    else 
        cout << sum / 2;
    return 0;
}