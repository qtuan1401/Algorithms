#include <bits/stdc++.h>

#define vall(a) (a.begin(), a.end())

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;

int ans[6][6], cnt[6][6], marked[6];

vector < vector < int > > seg;
vector < int > cur;

string r, c;
int n;

bool check(vector < int > & a, int col) {
    int st = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) continue;
        st++;
        if (cnt[i][a[i]] > 0) return false;
        char cc = char(a[i] - 1 + 'A');
        if (cnt[i][1] + cnt[i][2] + cnt[i][3] == 0 && cc != r[i]) return false;
        if (st == 1 && cc != c[col]) return false;
    }

    return true;
}

bool found = false;

void recur(int p) {
    if (found) return;
    if (p == n) {
        bool ok = true;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (ans[i][j] == 0) continue;
                cnt++;
                if (cnt == 1 && char(ans[i][j] - 1 + 'A') != r[i]) {
                    ok = false;
                    break;
                }
            }
            if (ok == false) return;
        }
        found = true;
        cout << "Yes\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (ans[i][j] == 0) cout << ".";
                else cout << char(ans[i][j] - 1 + 'A');
            }
            cout << '\n';
        }

        return ;
    }
    for (auto & e : seg) {
        if (check(e, p)) {
            for (int i = 0; i < n; i++) {
                ans[i][p] = e[i];
                cnt[i][e[i]]++;
            }
            recur(p + 1);
            for (int i = 0; i < n; i++) {
                ans[i][p] = 0;
                cnt[i][e[i]]--;
            }
        }
    }
}

void gen(int p) {
    if (p == n) {
        vector < int > cnt(3, 0);
        for (auto & e : cur) {
            if (e == 0) continue;
            cnt[e - 1]++;
        }
        if (cnt[0] + cnt[1] + cnt[2] == 3) seg.push_back(cur);
        return ;
    }
    for (int i = 0; i <= 3; i++) {
        if (marked[i] && i != 0) continue;
        cur.push_back(i);
        marked[i] = true;
        gen(p + 1);
        marked[i] = false;
        cur.pop_back();
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    while (tests--) {
        cin >> n;
        cin >> r >> c;
        
        for (int i = 0; i < n; i++) marked[i] = false;
        gen(0);
        recur(0);

        if (!found) cout << "No\n";
    }
    return 0;
}