#include <bits/stdc++.h>

using namespace std;

string s, t;

bool isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> s;
    cin >> t;
    if (s.size() != t.size()) {
        cout << "No";
        return 0;
    }
    for(int i = 0; i < s.size(); i++)
        if (isVowel(s[i]) != isVowel(t[i])) {
            cout << "No";
            return 0;
        }
    cout << "Yes";

    return 0;   
}