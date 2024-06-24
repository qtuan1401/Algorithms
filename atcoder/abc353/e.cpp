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

struct Trie {
    Trie * child[26];
    int cnt;

    Trie() {
        for (int i = 0; i < 26; i++) child[i] = NULL;
        cnt = 0;
    }
};

Trie * root;
long long update(string & s) {
    Trie * p = root;
    int n = s.size();
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int c = s[i] - 'a';
        if (p -> child[c] == NULL) {
            p -> child[c] = new Trie();
        }
        p = p -> child[c];
        long long curCnt = p -> cnt;
        ans -= curCnt * i;
        ans += curCnt * (i + 1);
        p -> cnt++;
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
        cin >> n;
        long long ans = 0;
        root = new Trie();
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            ans += update(s);
        }

        cout << ans << '\n';
    }
    return 0;
}