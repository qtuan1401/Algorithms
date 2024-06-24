#include <bits/stdc++.h>

using namespace std;

void calc(string & s, string & t, int & a) {
    for (int i = 0, j = 0; i < s.size() && j < t.size(); i++) {
        if (s[i] == t[j]) {
            j++;
            a++;
        }
    }
}

int bs(int l, int r, int val, vector < int > & suffix, int target) {
    int ans = r + 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (val + suffix[mid] >= target) {
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    return ans;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    while (tests--) {
        int n;  
        string t, revT;
        cin >> n >> t;
        vector < string > s(n), revS(n);
        revT = t;
        reverse(revT.begin(), revT.end());
        for (int i = 0; i < n; i++) {
            cin >> s[i];
            revS[i] = s[i];
            reverse(revS[i].begin(), revS[i].end());
        }
        vector < int > prefix(n), suffix(n);
        for (int i = 0; i < n; i++) {
            calc(s[i], t, prefix[i]);
            calc(revS[i], revT, suffix[i]);
            // cout << prefix[i] << " " << suffix[i] << endl;
        }

        sort(suffix.begin(), suffix.end());

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int pos = bs(0, n - 1, prefix[i], suffix, (int)t.size());
            ans += n - pos;
            // cout << i << ": " << pos << endl;
        }
        cout << ans << '\n';
    }
    return 0;
}