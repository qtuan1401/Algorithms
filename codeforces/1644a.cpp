#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        vector < int > pos(256, INF);
        for (int i = 0; i < s.size(); i++)
            pos[s[i]] = min(pos[s[i]], i);
        // cout << pos['r'] << " " << pos['R'] << " " << pos['b'] << " " << pos['B'] << " " << pos['g'] << " " << pos['G'] << endl;
        if (pos['r'] > pos['R'] || pos['b'] > pos['B'] || pos['g'] > pos['G']) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}