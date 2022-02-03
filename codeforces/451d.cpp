#include <bits/stdc++.h>

using namespace std;

int cntOdd[2], cntEven[2];
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> s;
    long long resOdd = 0, resEven = 0;
    for(int i = 0; i < s.size(); i++) {
        resOdd++;
        int id = s[i] - 'a';
        if (i % 2 == 0) {
            resOdd += cntEven[id];
            resEven += cntOdd[id];
            cntEven[id]++;
        } else {
            resOdd += cntOdd[id];
            resEven += cntEven[id];
            cntOdd[id]++;
        }
    }
    cout << resEven << " " << resOdd;
    return 0;
}