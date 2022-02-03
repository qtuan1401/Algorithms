#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    vector < int > nums;
    for (int i = 1; i < (1 << 20); i++) {
        if (__builtin_popcount(i) % 2 == 0)
            nums.push_back(i);
    }
    while (T--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
            cout << nums[i] << " ";
        cout << '\n';
    }
    return 0;
}