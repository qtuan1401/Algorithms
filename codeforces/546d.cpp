#include <bits/stdc++.h>

using namespace std;

const int MXN = 5e6 + 10;

long long sum[MXN];
bool marked[MXN];

void eratos(int n) {
    for(int i = 2; i <= n; i++) {
        if (sum[i] == 0) {
            for(long long j = i; j <= n; j *= i) 
                marked[j] = 1;
        }
        if (marked[i])
            for(int j = i; j <= n; j += i)
                sum[j]++;
    }
    for(int i = 2; i <= n; i++)
        sum[i] += sum[i - 1];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    eratos(5e6);
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        cout << sum[a] - sum[b] << '\n';
    }
    return 0;
}