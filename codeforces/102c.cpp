#include <bits/stdc++.h>

using namespace std;

pair < int , int > cnt[26];
bool marked[26];

int main() {
    ios_base::sync_with_stdio(0);
    string s;
    cin >> s;
    //cout << s << endl;
    int n = s.size();
    for(int i = 0; i < n; i++) {
        int pos = s[i] - 'a';
        cnt[pos].first++;
        cnt[pos].second = pos;
    }
    sort(cnt, cnt + 26);
    int k, res = 0;
    cin >> k;
    string ans;
    for(int i = 0; i < 26; i++)
        if (cnt[i].first > 0) {
            res++;
            k -= cnt[i].first;
            if (k >= 0)
                res--;
            //cout << k << " " << i << endl;
            if (k < 0) {
            //    cout << k << " " << i << endl;
                marked[cnt[i].second] = true;
            }
        }
    //cout << marked[0] << endl;
    cout << res << '\n';
    for(int i = 0; i < n; i++)
        if (marked[s[i] - 'a'])
            cout << s[i];
    return 0;
}