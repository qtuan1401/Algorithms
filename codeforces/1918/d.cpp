#include <bits/stdc++.h>

using namespace std;

template < class T >
void resetVec(vector < T > & a, int n, T val) {
    a.clear();
    a.resize(n, val);
}

typedef long double ld;
typedef long long ll;
typedef pair < long long, int > pii;

const long long INF = 1e18;

vector < int > a;
vector < long long > sum;

bool check(long long target) {
    // cout << target << endl;
    priority_queue < pii, vector < pii >, greater < pii > > heap;
    
    int n = a.size();
    vector < long long > f(n, INF);
    heap.push({0, -1});
    long long tot = 0;
    for (int i = 0; i < n; i++) {
        
        while (tot - (heap.top().second == -1 ? 0 : sum[heap.top().second]) > target) heap.pop();
        if (heap.empty()) return false;

        f[i] = heap.top().first + a[i];
        tot += a[i];
        heap.push({f[i], i});
    }

    return f[n - 1] <= target;
}

long long bs(long long l, long long r) {
    long long ans = 0;
    while (l <= r) {
        long long mid = (l + r) / 2;
        if (check(mid)) {
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
    int tests;
    cin >> tests;
    while (tests--) {
        int n;
        cin >> n;
        resetVec < int > (a, n + 1, 0);
        resetVec < long long > (sum, n + 1, 0);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum[i] = a[i] + (i == 0 ? 0 : sum[i - 1]);
        }
        sum[n] = sum[n - 1];

        cout << bs(1, INF) << '\n';
    }
    return 0;
}