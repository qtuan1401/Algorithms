#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;

long long calcPow(long long a, int n) {
    long long res = 1;
    for (int i = 0; i < n; i++) res = res * a;
    return res;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    while (tests--) {
        long long n;
        cin >> n;
        for (int i = 1; i <= 15; i++) {
            if (calcPow(i, i) == n) {
                cout << i << '\n';
                exit(0);
            }
        }

        cout << "-1\n";
    }
    return 0;
}