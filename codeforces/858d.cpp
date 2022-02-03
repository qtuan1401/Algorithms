#include<bits/stdc++.h>

using namespace std;

const int MXN = 7e4 + 10;

unordered_map < string, int > mp, cnt[MXN];

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < 9; j++) {
            string temp = "";
            for(int k = j; k < 9; k++) {
                temp += s[k];
                mp[temp]++;
                cnt[i][temp]++;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        string s = "99999999999999999999";
        for(map < string, int > :: iterator it = cnt[i].begin(); it != cnt[i].end(); it++) {
            string temp = (*it).first;
            int val = (*it).second;
            if (mp[temp] == val && temp.size() < s.size())
                s = temp;
        }
        cout << s << '\n';
    }
    return 0;
}
