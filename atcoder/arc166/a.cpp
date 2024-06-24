#include <bits/stdc++.h>

using namespace std;

bool check(string & s, string & t) {
    int n = s.size();
    // cout << s << " " << t << endl;
    vector < int > cnts(2, 0), cntt(2, 0);
    for (int i = 0; i < n; i++) {
        cnts[0] += s[i] == 'A';
        cnts[1] += s[i] == 'B';
    }
    for (int i = 0; i < n; i++) {
        cntt[0] += t[i] == 'A';
        cntt[1] += t[i] == 'B';
    }

    if (cnts[0] > cntt[0] || cnts[1] > cntt[1]) return false;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'C' && cnts[0] < cntt[0]) {
            s[i] = 'A';
            cnts[0]++;
        } else if (s[i] == 'C') {
            s[i] = 'B';
            cnts[1]++;
        }
    }

    vector < int > ps, pt;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'B') ps.push_back(i);
        if (t[i] == 'B') pt.push_back(i);
    } 

    if (ps.size() != pt.size()) return false;

    for (int i = 0; i < ps.size(); i++) {
        // cout << ps[i] << " " << pt[i] << endl;
        if (pt[i] > ps[i]) return false;
    }
    return true;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests;
    cin >> tests;
    while (tests--) {
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        s += "C";
        t += "C";
        n++;

        bool ok = true;
        string ss = "", tt = "";
        vector < string > s1, t1;
        
        for (int i = 0; i < n; i++) {
            if (t[i] == 'C' && s[i] != 'C') {
                ok = false;
                break;
            }
            if (t[i] == 'C' && s[i] == 'C') {
                s1.push_back(ss);
                t1.push_back(tt);
                ss = "";
                tt = "";
            } else {
                ss += s[i];
                tt += t[i];
            }
        }

        if (!ok) {
            cout << "No\n";
            continue;
        }
        
        for (int i = 0; i < s1.size(); i++) {
            ok &= check(s1[i], t1[i]);
        }

        cout << (ok ? "Yes" : "No") << '\n';
    }
    return 0;
}