#include <bits/stdc++.h>

using namespace std;

string solve(string s1, string s2) {
    int n = s1.size(), m = s2.size();
    int pos1 = 0, pos2 = 0, pre1 = 0, pre2 = 0;
    while (pos1 < n && pos2 < m) {
        while (pos1 < n - 1 && s1[pos1 + 1] == s1[pos1])
            pos1++;
        while (pos2 < m - 1 && s2[pos2 + 1] == s2[pos2])
            pos2++;
        if (s1[pos1] != s2[pos2]) 
            return "NO";
        if (pos1 - pre1> pos2 - pre2)
            return "NO";
        pre1 = pos1; pre2 = pos2;
        pos1++; pos2++;
    }
    if (pos1 != n || pos2 != m)
        return "NO"; 
    return "YES";
}

int main() {
    //freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        cout << solve(s1, s2) << '\n';
    }
    return 0;
}