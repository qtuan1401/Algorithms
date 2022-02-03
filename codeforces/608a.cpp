#include<bits/stdc++.h>

using namespace std;

int n, s;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> s;
    int res = s;
    for(int i = 0; i < n; i++) {
        int f, t;
        cin >> f >> t;
        res = max(res, f + t);
    }
    cout << res;
    return 0;
}
