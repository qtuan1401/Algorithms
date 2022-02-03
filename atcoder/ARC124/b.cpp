#include <bits/stdc++.h>

using namespace std;

const int LIM_N = 2e3 + 10;

int a[LIM_N], b[LIM_N];
int n;

int main() {
    // freopen("test.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        // xorA ^= a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        // xorB ^= b[i];
    }
    multiset < int > s;
    set < int > res;
    for (int i = 0; i < n; i++) {
        s.clear();
        for (int j = 0; j < n; j++)
            if (j != i)
                s.insert(b[j]);
        int x = a[0] ^ b[i];
        for (int k = 1; k < n; k++) {
            int y = a[k] ^ x;
            if (s.find(y) != s.end())
                s.erase(s.find(y));
        }
        if (s.size() == 0)
            res.insert(x);
    }
    cout << res.size() << '\n';
    for (auto it = res.begin(); it != res.end(); it++)
        cout << *it << '\n';
}