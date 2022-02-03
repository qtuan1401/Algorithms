#include <bits/stdc++.h>

using namespace std;

string s, t;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> s >> t;
    if (s.size() < t.size()) {
        cout << "need tree";
        return 0;
    } else {
        if (s.size() > t.size()) {
            int j = 0;
            for(int i = 0; i < s.size() && j < t.size(); i++)
                if (s[i] == t[j])
                    j++;
            if (j == t.size()) {
                cout << "automaton";
                return 0;
            }
        }
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if (s == t) {
            cout << "array";
            return 0;
        }
        int j = 0;
        for(int i = 0; i < s.size() && j < t.size(); i++)
            if (s[i] == t[j])
                j++;
        if (j == t.size()) {
            cout << "both";
        } else 
            cout << "need tree";
    }
    return 0;
}