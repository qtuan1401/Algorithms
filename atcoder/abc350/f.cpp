#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair < int, int > pii;

char calc(char c, int depth) {
    if (depth % 2 == 0) return c;
    else if (islower(c)) {
        return toupper(c);
    } else {
        return tolower(c);
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    while (tests--) {
        string s;
        cin >> s;
        int n = s.size();

        stack < int > stk;
        string ans;
        string temp = s;
        // for (int i = 0; i < n; i++) {
        //     if (isalpha(s[i])) ans += s[i];
        // }


        vector < int > val(n, 0);

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                stk.push(i);
            } else if (s[i] == ')') {
                val[stk.top()] = i + stk.top();
                stk.pop();
            }
        }

        int depth = 0, cnt = 0;
        long long sum = 0;
        vector < pair < int, char > > vans;
        for (int i = 0; i < n; i++) {
            // cout << i << " " << s[i] << endl;
            if (s[i] == '(') {
                stk.push(i);
                depth++;
                sum += (depth % 2 == 0 ? -1 : 1) * val[i];
            } else if (s[i] == ')') {
                sum -= (depth % 2 == 0 ? -1 : 1) * val[stk.top()];
                stk.pop();
                depth--;
            } else {
                long long pos = sum + (depth % 2 == 0 ? 1 : -1) * i;
                // cout << pos << " " << sum << " " << cnt << " " << temp.size() << " " << pos - cnt << endl;
                vans.push_back(pii(pos, calc(s[i], depth))); 
                // cout << "**\n";
            }
        }
        sort(vans.begin(), vans.end());

        for (auto & e : vans) cout << e.second; 
    }
    return 0;
}