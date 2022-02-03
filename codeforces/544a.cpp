#include <bits/stdc++.h>

using namespace std;

bool marked[30];
string ans[30];
string s;
int r, n;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    cin >> s;
    for(int i = 0; i < s.size(); i++) {
        if (marked[s[i] - 'a'] == false && r < n) {
            marked[s[i] - 'a'] = true;
            ans[++r] = s[i];
        } else
            ans[r] = ans[r] + s[i];
        //cout << ans[r] << " " << r << endl;
    }
    if (r != n) {
        cout << "NO";
    } else {
        cout << "YES\n";
        for(int i = 1; i <= r; i++)
            cout << ans[i] << '\n';
    }
    return 0;
}