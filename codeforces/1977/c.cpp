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

int getGcd(int a, int b) {
    if (b == 0) return a;
    return getGcd(b, a % b);
}

int getBit(int x, int i) {
    return (x >> i) & 1;
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
        vector < int > a(n);
        map < long long, int > mp;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            mp[a[i]]++;
        }
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
        vector < long long > lcm(n);
        vector < int > nums;
        for (int i = 0; i < n; i++) {
            lcm[i] = a[0];
            for (int j = 1; j <= i; j++) {
                lcm[i] = (lcm[i] * a[j]) / getGcd(a[j], lcm[i]);
            }
            if (i > 1) {
                if (a[i] % lcm[i] == 0) continue;
                if (lcm[i] == lcm[i - 1]) continue;
            }
            nums.push_back(a[i]);
        }

        
        int sz = nums.size(), ans = 0;
        for (int mask = 1; mask < (1 << sz); mask++) {
            long long lcm = 1;
            int sum = 0;
            vector < int > b;
            for (int i = 0; i < sz; i++) {
                if (getBit(mask, i) == 1) {
                    lcm = (lcm * nums[i]) / getGcd(lcm, nums[i]);
                    b.push_back(nums[i]);
                }
            }

            int m = b.size();
            set < long long > fin;
            for (int mask1 = 0; mask1 < (1 << m); mask1++) {
                long long lcm1 = 1;
                for (int i = 0; i < m; i++) {
                    if (getBit(mask1, i)) {
                        lcm1 = (lcm1 * b[i]) / getGcd(lcm1, b[i]);
                        if (mp.count(lcm1))
                            fin.insert(lcm1);
                    }
                }
            }

            for (auto & e : fin) sum += mp[e];

            if (mp.count(lcm) == 0) {
                ans = max(ans, sum);
            }
        }

        cout << ans << '\n';
    }
    return 0;
}
