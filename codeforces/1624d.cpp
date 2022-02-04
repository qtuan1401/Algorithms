#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector < int > cnt(26, 0);
        for (int i = 0; i < n; i++)
            cnt[s[i] - 'a']++;
        int remain = 0, sum = 0;
        for (int i = 0; i < 26; i++) {
            sum += cnt[i] / 2;
            remain += (cnt[i] % 2 != 0);
        }
        int len = sum / k;
        if (len == 0) {
            cout << "1\n";
            continue;
        }
        remain += (sum % k) * 2;
        cout << len * 2 + (remain >= k) << '\n';
    }
    return 0;
}