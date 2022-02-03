#include <bits/stdc++.h>

using namespace std;

int n, k;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    cin >> s;
    s = s + "#";
    int res = 0;
    for(int j = 0; j < 26; j++) {
        int cnt = 0, sum = 0;
        for(int i = 0; i <= n; i++) {
            if (s[i] - 'a' == j)
                cnt++;
            else {
                sum += max(0, cnt / k);
                cnt = 0;
            }
            //cout << cnt << " ";
        }
        res = max(res, sum);
        //cout << endl;
    }
    cout << res;
    return 0;
}