#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long x;
    cin >> x;
    for(long long i = 1; i < 100000; i++) {
        long long m = i * i - x;
        if (m <= 0)
            continue;
        long long temp = sqrt(m);
        if (temp * temp == m) {
            if (i / temp > (i / (temp + 1))) {
                cout << i << " " << i / temp << '\n';
                return ;
            }
        } 
    }
    cout << "-1\n";
}

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}