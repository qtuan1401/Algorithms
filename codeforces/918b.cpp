#include <bits/stdc++.h>

using namespace std;

map < string, string > mp;
int n, m;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        mp[s2] = s1;
    }

    for(int i = 0; i < m; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        string s3 = s2;
        s3.erase(s3.size() - 1);
        cout << s1 << " " << s2 << " #" << mp[s3] << '\n';
    }
    return 0;
}