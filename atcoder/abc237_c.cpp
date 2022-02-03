#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    string s;
    cin >> s;

    int cntR = 0, cntL = 0;
    for (int i = (int)s.size() - 1; i >= 0; i--) {
        if (s[i] != 'a') break;
        cntR++;
    }

    for (int i = 0; i < s.size(); i++) {
        if (s[i] != 'a') break;
        cntL++;
    }

    if (cntL > cntR) {
        cout << "No\n";
        return 0;
    }

    string ns = "";
    for (int i = cntL; i < cntR; i++)
        ns += "a";
    
    ns += s;

    s = ns;
    reverse(s.begin(), s.end());

    if (s == ns) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}