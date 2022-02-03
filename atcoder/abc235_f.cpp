#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

int getBit(int x, int i) {
    return (x >> i) & 1;
}

int onBit(int x, int i) {
    return x | (1 << i);
}

int offBit(int x, int i) {
    return x ^ (1 << i);
}

typedef pair < int, int > PII;

vector < vector < PII > > f;
vector < int > pp10;
string s;
int finalState, len, n;

PII memo(int i, int state, bool isSmaller) {
    if (i == len) {
        return PII(0, (state & finalState) == finalState);
    }

    if (isSmaller && f[i][state].first != -1) return f[i][state];
    PII sum = PII(0, 0);
    int num = s[i] - '0';
    for (int j = 0; j <= (isSmaller ? 9 : num); j++) {
        int newState = state | (1 << j);
        if (state == 0 && j == 0)
            newState = 0;
        PII temp = memo(i + 1, newState, isSmaller || (j < num));
        sum.first = (1ll * sum.first + ((1ll * j * pp10[len - i - 1]) % MOD * temp.second) % MOD + temp.first) % MOD;
        sum.second = (sum.second + temp.second) % MOD;
    }
    if (isSmaller) f[i][state] = sum;
    return sum;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> s;
    len = s.size();
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        finalState = onBit(finalState, x);
    }

    pp10.resize(s.size());
    pp10[0] = 1;
    for (int i = 1; i < s.size(); i++)
        pp10[i] = (1ll * pp10[i - 1] * 10) % MOD;

    f.resize(s.size() + 1, vector < PII > (1024, PII(-1, 0)));
    cout << memo(0, 0, 0).first;
}