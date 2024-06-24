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
        int n;
        cin >> n;
        vector < int > ans(n);
        vector < pii > a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].first;
            a[i].second = i;
        }

        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++) {
            vector < pii > nums;
            nums.push_back(a[i]);
            while (i + 1 < n && (a[i].first ^ a[i + 1].first) < 4) {
                nums.push_back(a[i + 1]);
                i++;
            }

            sort(nums.begin(), nums.end());

            vector < int > pos;
            for (auto & num : nums) pos.push_back(num.second);
            sort(pos.begin(), pos.end());
            for (int i = 0; i < nums.size(); i++) {
                ans[pos[i]] = nums[i].first;
            }  
        }

        for (int i = 0; i < n; i++) cout << ans[i] << " ";
        cout << '\n';
    }
    return 0;
}