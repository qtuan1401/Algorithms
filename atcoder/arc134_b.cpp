#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector < vector < int > > pos(26);
    for (int i = 0; i < n; i++)
        pos[s[i] - 'a'].push_back(i);
    int l = 0, r = n - 1;
    vector < int > swapL;
    vector < int > swapR;
    for (auto & num : pos) {
        for (int i = (int)num.size() - 1; i >= 0; i--) {
            while (l < n && s[l] == s[num[i]]) l++;
            if (num[i] < l || num[i] > r) continue;
            if (s[num[i]] > s[l]) continue;
            swapL.push_back(l);
            l++; 
            swapR.push_back(num[i]);
            r = num[i];
        }
    }
    for (int i = 0; i < swapL.size(); i++) swap(s[swapL[i]], s[swapR[i]]);
    cout << s << '\n';
    return 0;
}