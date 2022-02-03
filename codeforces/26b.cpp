#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    string s;
    cin >> s;
    int res = 0, sum = 0;
    for(int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            sum++;
            res++;
        } else if (sum > 0) {
            res++;
            sum--;
        }
    }
    cout << res - sum;
    return 0;
}