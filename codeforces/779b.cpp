#include <bits/stdc++.h>

using namespace std;

string s;
int k;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> s;
    cin >> k;
    int cnt = 0, res = 0;
    for(int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == '0')
            cnt++;
        else 
            res++;
        if (cnt == k) {
            cout << res;
            return 0;
        }
    }
    cout << s.size() - 1;
    return 0;
}