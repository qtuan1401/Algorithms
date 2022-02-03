#include <bits/stdc++.h>

using namespace std;

string s;
int cnt[100];
int T;

inline bool check(int a, int b) {
    return (abs(a - b) != 1);
}

void print(vector < int > a, vector < int > b) {
    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j < cnt[a[i]]; j++)
            cout << char(a[i] + 'a');
    }
    for(int i = 0; i < b.size(); i++) {
        for(int j = 0; j  < cnt[b[i]]; j++)
            cout << char(b[i] + 'a');
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> T;
    while (T--) {
        cin >> s;
        for(int i = 0; i < 26; i++)
            cnt[i] = 0;
        for(int i = 0; i < s.size(); i++)
            cnt[s[i] - 'a']++;
        vector < int > odd, even;
        for(int i = 0; i < 26; i++) 
            if (cnt[i] > 0) {
                if (i % 2 == 1)
                    odd.push_back(i);
                else even.push_back(i);
            }
        if (odd.empty() || even.empty()) 
            print(odd, even);
        else if (check(even.back(), odd[0])) 
            print(even, odd);
        else if (check(odd.back(), even[0]))
            print(odd, even);
        else cout << "No answer";
        cout << '\n';
    }
    return 0;
}