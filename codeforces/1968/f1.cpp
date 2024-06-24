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

vector < int > z;

int n;

int check(int target, int threshold) {
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        if (z[i] >= threshold) {
            cnt++;
            i += threshold - 1;
        }
    }

    return cnt >= target;
}

int bs(int l, int r, int k) {
    int ans = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(k, mid)) {
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
    }

    return ans;
}

int zFunc(string & s) {
    int l = 0, r = 0;
    int ans = 0;
    for(int i = 1; i < n; i++) {
        if (i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        
        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    z[0] = n;
    return ans;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests;
    cin >> tests;
    while (tests--) {
        int l, r;
        cin >> n >> l >> r;
        resetVec < int > (z, n, 0);
        string s;
        cin >> s;
        zFunc(s);
        // for (int i = 0; i < n; i++) cout << z[i] << " ";
        // cout << endl;
        cout << bs(1, n, r) << '\n';
    }
    return 0;
}