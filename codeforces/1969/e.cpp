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

vector < int > a, marked;
int n;
long long ans;

bool process(int l, int r, vector < int > & a) {
    if (l > r) return true;
    int cnt = 0;
    for (int i = l; i <= r; i++) {
        if (marked[a[i]] == 0) cnt++;
        else cnt--;
        marked[a[i]]++;
    }

    for (int i = l; i <= r; i++) {
        marked[a[i]]--;
    }

    return cnt > 0;
}

void solve(int l, int r, vector < int > & a) {
    if (l >= r) return;
    int mid = (l + r) >> 1;
    solve(l, mid, a);
    solve(mid + 1, r, a);
    // cout << l + mid / 2 << " " << r - mid / 2 << endl;
    solve(l + mid / 2, r - (mid + 1) / 2 - 1, a);

    int pl = l - 1;
    int pr = r + 1;
    for (int i = mid; i >= l; i--) {
        if (a[i] > n) {
            pl = i;
            break;
        }
    }

    for (int i = mid + 1; i <= r; i++) {
        if (a[i] > n) {
            pr = i;
            break;
        }
    }
    // cout << l << " " << r << " " << pl << " " << pr << " " << process(pl + 1, pr - 1, a) << endl;
    if (process(pl + 1, pr - 1, a)) return;
    a[mid] = n + 1;
    ans++;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests;
    cin >> tests;
    while (tests--) {
        ans = 0;
        cin >> n;
        resetVec < int > (a, n, 0);
        for (int i = 0; i < n; i++) cin >> a[i];
        resetVec < int > (marked, n + 1, 0);
        solve(0, n - 1, a);
        cout << ans << '\n';
    }
    return 0;
}