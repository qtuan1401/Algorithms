#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector < int > v;
   // v.push_back(0);
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == 1)
            v.push_back(i);
    }
    int res = (v.size() > 0);
    for(int i = 1; i < v.size(); i++)
        res += min(2, v[i] - v[i - 1]);
    cout << res;
    return 0;
}