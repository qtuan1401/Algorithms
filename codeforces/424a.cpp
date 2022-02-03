#include <bits/stdc++.h>

using namespace std;

int n;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> s;
    int x = count(s.begin(), s.end(), 'x');
    int cnt = 0;
    for(int i = 0; i < s.size(); i++) {
        if (x < n / 2 && s[i] == 'X') {
            cnt++; 
            x++; 
            s[i] = 'x';
        } else if (x > n/2 && s[i] == 'x') {
            cnt++; 
            x--; 
            s[i] = 'X';
        }
    }
    cout << cnt << '\n';
    cout << s;
}
