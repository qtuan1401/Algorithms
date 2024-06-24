#include <bits/stdc++.h>

#define vall(a) (a.begin(), a.end())

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;

bool check(int x) {
    int a = x % 10;
    x /= 10;
    return (x % 10) * (x / 10) == a;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    while (tests--) {
        int n;
        cin >> n;
        for (int i = n; i <= 999; i++) {
            if (check(i)) {
                cout << i << '\n';
                break;
            }
        }
    }
    return 0;
}