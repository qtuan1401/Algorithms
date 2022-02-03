#include <bits/stdc++.h>

using namespace std;

const int md = 100;

string s;
int n, res;
int cnt[100];

int main() {
    cin >> n;
    cin >> s;
    if (n > 26) {
        cout << "-1";
    } else {
        for(int i = 0; i < n; i++) {
            if (cnt[s[i] - 'a'] > 0)
                res++;
            cnt[s[i] - 'a']++;
        }
        cout << res;
    }
    return 0;
}