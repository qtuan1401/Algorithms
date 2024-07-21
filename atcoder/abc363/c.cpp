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
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        int ans = 0;
        set < string > st;
        do {
            bool valid = true;
            for (int i = 0; i <= n - k; i++) {
                int r = i + k - 1;
                int l = i;
                bool ok = false;
                while (l < r) {
                    if (s[id[l]] != s[id[r]]) {
                        ok = true;
                        break;
                    }
                    l++; r--;
                }
                if (!ok) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                string s1 = "";
                for (int i = 0; i < n; i++) s1 += s[id[i]];
                st.insert(s1);
            }
        } while (next_permutation(id.begin(), id.end()));

        cout << st.size() << '\n';
    }
    return 0;
}
