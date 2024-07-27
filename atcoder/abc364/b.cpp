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

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    while (tests--) {
        int n, m;
        cin >> n >> m;
        int x, y;
        cin >> x >> y;
        vector < string > c(n);
        for (int i = 0; i < n; i++) cin >> c[i];
        x--; y--;
        map < char, pii > dir;
        dir['L'] = pii(0, -1);
        dir['R'] = pii(0, 1);
        dir['U'] = pii(-1, 0);
        dir['D'] = pii(1, 0);
        string s;
        cin >> s;
        for (int i = 0; i < s.size(); i++) {
            int nx = x + dir[s[i]].first;
            int ny = y + dir[s[i]].second;
            
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (c[nx][ny] == '#') continue;
            x = nx;
            y = ny;
        }

        cout << x + 1 << " " << y + 1 << '\n';
    }
    return 0;
}