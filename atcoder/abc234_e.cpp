#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    long long x;
    cin >> x;
    long long res = 111111111111111111;
    for (int diff = -9; diff <= 9; diff++) {
        for (int digit = 0; digit <= 9; digit++) {
            long long num = digit, cur = num;
            int cnt = 1;
            while (num < x && cnt <= 18) {
                int nxt = cur + diff;
                if (nxt < 0 || nxt > 9)
                    break;
                num = num * 10 + nxt;
                cur = nxt;
                cnt++;
                if (num >= x)
                    res = min(res, num);
            }
        }
    }
    cout << res;
    return 0;
}