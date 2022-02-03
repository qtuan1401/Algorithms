#include <bits/stdc++.h>

using namespace std;

string s;
int f[1000010];

int main() {
    ios_base::sync_with_stdio(0);
    cin >> s;
    int cnt = 0;
    for(int i = 0; i < s.size(); i++)
        if (s[i] == 'F') {
            if (cnt == 0) {
                f[cnt] = i;
            } else {
                if (cnt == i)
                    f[cnt] = 0;
                else f[cnt] = max(f[cnt - 1] + 1, i - cnt);
            }
            cnt++;
        }
    if (cnt == 0 || cnt == s.size())
        cout << 0;
    else cout << f[cnt - 1];
    return 0;
}