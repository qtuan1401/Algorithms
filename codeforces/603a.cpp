#include<bits/stdc++.h>

using namespace std;

int res = 1, n;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> s;
    for(int i = 1; i < n; i++) 
        res += (s[i - 1] != s[i]);
    cout << min(res + 2, n);
    return 0;
}   