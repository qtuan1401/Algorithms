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
    int tests;
    cin >> tests;
    while (tests--) {
        int n, k;
        cin >> n >> k;
        vector < int > a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        if (n == k) {
            cout << "0\n";
            continue;
        }

        vector < pii > prof;
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            if (b[i] - a[i] <= 0) continue;
            sum -= a[i];
            prof.push_back(pii(b[i], a[i]));
        }

        n = prof.size();
        if (n == 0) {
            cout << "0\n";
            continue;
        }
        
        sort(prof.begin(), prof.end(), [&](pii l, pii r) {
            if (l.first == r.first) return l.second > r.second;
            return l.first < r.first;
        });

        // for (int i = 0; i < n; i++) {
        //     cout << prof[i].first << " " << prof[i].second << endl;
        // }

        for (int i = 0; i < n - k; i++) sum += prof[i].first;
        long long ans = sum;
        priority_queue < long long > heap;
        for (int i = n - k; i < n; i++) heap.push(prof[i].second);
        for (int i = n - k - 1; i >= 0; i--) {
            if (heap.empty()) break;
            sum += heap.top();
            heap.pop();
            sum -= prof[i].first;
            heap.push(prof[i].second);
            ans = max(ans, sum);
        }

        cout << max(0ll, ans) << '\n';
    }   
    return 0;
}