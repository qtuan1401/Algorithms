#include <bits/stdc++.h>
 
using namespace std;
 
const char c[] = {'R', 'G', 'B'};

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    string s;
    cin >> n >> s;
    int cnt = 0;
    for(int i = 0; i < n - 1; i++)
        if (s[i + 1] == s[i]) {
            cnt++;
            for(int j = 0; j < 3; j++) {
                char x = c[j];
                if (x != s[i] && x!= s[i + 2])
                    s[i + 1] = x;
            }
        }
    cout << cnt << "\n" << s;
    return 0;
}
