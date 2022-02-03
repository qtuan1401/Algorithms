#include <bits/stdc++.h>

using namespace std;

string s, t;
int n;
vector < int > d1, d2;

int main() {
    //freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n;
    cin >> s;
    cin >> t;
    for(int i = 0; i < n; i++) {
        if (s[i] == 'a' && t[i] == 'b')
            d1.push_back(i + 1);
        if (s[i] == 'b' && t[i] == 'a')
            d2.push_back(i + 1);
    }
    if ((d1.size() + d2.size()) & 1) 
        cout << "-1";
    else {
        cout << (d1.size() + d2.size()) / 2 + (d1.size() & 1) << '\n';
        int l = 0;
        if (d1.size() & 1) {
            cout << d1[0] << " " << d1[0] << '\n';
            d2.push_back(d1[0]);
            l = 1;
        }
        for(int i = l; i < d1.size(); i += 2)
            cout << d1[i] << " " << d1[i + 1] << '\n';
        for(int i = 0; i < d2.size(); i += 2)
            cout << d2[i] << " " << d2[i + 1] << '\n';
    }
    return 0;
}