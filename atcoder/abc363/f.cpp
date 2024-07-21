#include <bits/stdc++.h>

using namespace std;

template < class T >
void resetVec(vector < T > & a, int sz, T val) {
    a.clear();
    a.resize(sz, val);
}

typedef long double ld;
typedef long long ll;
typedef pair < int, int > pii;

long long calc(long long x) {
    vector < int > digits;
    while (x > 0) {
        if (x % 10 == 0) return -1;
        digits.push_back(x % 10);
        x /= 10;
    }

    long long ans = 0;
    for (auto & d : digits) ans = ans * 10 + d;
    return ans;
}

map < long long, string > memo;

string f(long long n) {
    if (memo.count(n) != 0) return memo[n];
    if (n == calc(n)) return to_string(n);
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            long long rev = calc(i);
            if (rev == -1) continue;
            if ((n / i) % rev != 0) continue;
            string res = f(n / i / rev);
            if (res == "") continue;
            return memo[n] = to_string(i) + "*" + res + "*" + to_string(rev);
        }
    }
    return "";
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
        
        string ans = f(n);
        if (ans == "") cout << "-1\n";
        else cout << ans << '\n';
    }
    return 0;
}