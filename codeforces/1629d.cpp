#include <bits/stdc++.h>

using namespace std;

bool check(string s) {
    string s1 = s;
    reverse(s1.begin(), s1.end());
    return (s1 == s);
}

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        bool found = false;
        map < string, int > origin;
        map < string, int > del;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            if (check(s)) {
                found = true;
            }

            // //ab[ba]
            // if (revOrigin.find(s) != revOrigin.end()) {
            //     found = true;
            // }

            // //ac[bca]
            // if (revDel.find(s) != revDel.end()) {
            //     found = true;
            // }

            string rev = s, s1 = s;
            reverse(rev.begin(), rev.end());

            // [ab]ba
            if (origin.find(rev) != origin.end()) {
                found = true;
            }

            // [acb]ca
            if (del.find(rev) != del.end()) {
                found = true;
            }

            // [ac]bca
            rev.erase(rev.size() - 1);
            if (origin.find(rev) != origin.end()) {
                found = true;
            }

            s.erase(s.size() - 1);
            del[s] = origin[s1] = 1;
        }
        if (found) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}