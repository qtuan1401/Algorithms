#include <bits/stdc++.h>

using namespace std;

long long sum[3];

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for(int k = 0; k <= 2; k++) {
        for(int i = 0; i < n - k; i++) {
            int x;
            cin >> x;
            sum[k] += x;
        }
    }
    cout << sum[0] - sum[1] << '\n' << sum[1] - sum[2];
    return 0;
}