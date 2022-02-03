#include <bits/stdc++.h>

using namespace std;

string s, s1;
int k;
vector < int > v[2];    

int main() {
    ios_base::sync_with_stdio(0);
    cin >> s;
    cin >> k;
    for(int i = 0; i < s.size(); i++)
        if (isalpha(s[i])) {
            s1 += s[i];
        } else if (s[i] == '?') {
            v[0].push_back(s1.size() - 1);
        } else 
            v[1].push_back(s1.size() - 1);
    //cout << s1.size() << " " << s1 << " " << v[0].sizeendl;
    if (s1.size() == k) {
        cout << s1;
    } else if (s1.size() > k) {
        for(int i = 0; i < v[1].size(); i++)
            v[0].push_back(v[1][i]);
        sort(v[0].begin(), v[0].end());
        if (s1.size() - v[0].size() <= k) {
            for(int i = 0, j = 0; i < s1.size(); i++) {
                //cout << v[0][j] << " " << j << endl;
                if (i == v[0][j] && j < s1.size() - k) {
                    j++;
                } else 
                    cout << s1[i];
            }
        } else {
            cout << "Impossible";
        }
    } else {
        if (v[1].size() > 0) {
            for(int i = 0; i < s1.size(); i++) {
                cout << s1[i];
                if (i == v[1][0]) {
                    for(int j = 0; j < k - s1.size(); j++)
                        cout << s1[i];
                }
            }
        } else {
            cout << "Impossible";
        }
    }
    return 0;
}