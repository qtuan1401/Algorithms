#include <bits/stdc++.h>

using namespace std;

template < class T >
void resetVec(vector < T > & a, int sz, T val) {
    a.clear();
    a.resize(sz, val);
}

typedef long double ld;
typedef long long ll;
typedef pair < int, int > pii;

int getMask(string & s) {
    int mask = 0;
    for (int i = 0; i < s.size(); i++) {
        int val = 0;
        mask *= 3;
        if (s[i] == '.') mask += 0;
        if (s[i] == 'B') mask += 1;
        if (s[i] == 'W') mask += 2;
    }
    return mask;
}

string extract(int x, int n) {
    string s = "";
    while (x > 0) {
        int val = x % 3;
        if (val == 0) s += ".";
        if (val == 1) s += "B";
        if (val == 2) s += "W";
        x /= 3;
    }
    while (s.size() < n) s += '.';
    reverse(s.begin(), s.end());
    return s;
}

int bfs(string & ss, string & tt) {
    queue < int > qu;
    vector < int > f(50000000, -1);
    f[getMask(ss)] = 0;
    qu.push(getMask(ss));
    while (qu.size()) {
        int v = qu.front(); qu.pop();
        string s = extract(v, ss.size());
        int pos = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '.') {
                pos = i;
                break;
            }
        }

        // left
        string temp = s;
        for (int i = pos - 2; i >= 0; i--) {
            swap(s[i], s[pos]);
            swap(s[i + 1], s[pos + 1]);
            int val = getMask(s);
            swap(s[i], s[pos]);
            swap(s[i + 1], s[pos + 1]);
            if (f[val] != -1) continue;
            f[val] = f[v] + 1;
            qu.push(val);
        }

        s = temp;
        // right
        for (int i = pos + 2; i < (int)s.size() - 1; i++) {
            swap(s[i], s[pos]);
            swap(s[i + 1], s[pos + 1]);
            int val = getMask(s);
            swap(s[i], s[pos]);
            swap(s[i + 1], s[pos + 1]);
            if (f[val] != -1) continue;
            f[val] = f[v] + 1;
            qu.push(val);
        }
    }

    return f[getMask(tt)];
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    freopen("../test.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    while (tests--) {
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        s += "..";
        t += "..";
        int ans = bfs(s, t);
        cout << ans << '\n';
    }
    return 0;
}