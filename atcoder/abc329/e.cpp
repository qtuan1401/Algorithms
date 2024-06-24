#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair < int, int > pii;

vector < int > remove(vector < int > order, int threshold) {
    for (int i = 0; i < order.size(); i++) {
        if (order[i] < threshold) {
            order.erase(i);
        }
    }

    return order;
}

void gen(int pos, string & cur, vector < int > & order, int pCur) {
    if (cur.size() == s.size()) {
        if (cur == s) {
            ans = true;
        }
        return;
    }

    if (pos + m - 1 >= n) return;

    if (cur.size() > pos + 1 && cur[pos] == s[pos]) {
        gen(pos + 1, cur, remove(order, pos + 1 - m));
    }

    for ()
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    while (tests--) {
        int n, m;
        cin >> n >> m;
        string s, t;
        cin >> s >> t;

        gen()
    }
    return 0;
}
// 3
// 0 1 2 3 4 5 6 7  