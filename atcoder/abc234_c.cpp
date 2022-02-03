#include <bits/stdc++.h>

using namespace std;

int getBit(long long x, int i) {
    return (x >> i) & 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    long long k;
    cin >> k;
    string res = "";
    for (int i = 0; i < 60; i++)
        if (getBit(k, i)) res += "2";
        else res += "0";
    reverse(res.begin(), res.end());
    while (res[0] == '0')
        res.erase(0, 1);
    cout << res;
    return 0;
}