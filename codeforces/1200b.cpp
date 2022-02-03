#include <bits/stdc++.h>

using namespace std;

vector < int > h;
int n, m, k;

void solve() {
    //cout << "*****\n";
    for(int i = 0; i < n - 1; i++) {
        int val = max(0, h[i + 1] - k);
        m -= val - h[i];
        //cout << h[i + 1] << " " << val << " " << h[i] << endl;
        if (m < 0) {
            cout << "NO\n";
            return ;
        }
    }
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m >> k;
        h.clear(); h.resize(n);
        for(int i = 0; i < n; i++)
            cin >> h[i];
        solve();
    }
    return 0;
}