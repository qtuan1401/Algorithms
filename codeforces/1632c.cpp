#include <bits/stdc++.h>

using namespace std;

int getBit(int x, int i) {
    return (x >> i) & 1;
}

int calc(int a, int b) {
    return abs(a - b) + 1;
}

int flipBit(int x, int i) {
    return x ^ (1 << i);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int a, b;
        cin >> a >> b;
        int res = min(b - a, calc(a | b, b));
        for (int i = a; i < b; i++)
            res = min(res, i - a + calc(i | b, b));
        int aa = a, bb = b;
        // for (int i = 29; i >= 0; i--)
        //     if (getBit(a, i) == 1 && getBit(b, i) == 0) {
        //         for (int j = i - 1; j >= 0; j--)
        //             if (getBit(b, j)) {
        //                 b = flipBit(b, j);
        //                 b = flipBit(b, i);
        //                 res = min(res, min(abs(b - a), calc(a | b, b)) + b - bb);
        //                 // cout << i << " " << j << endl;
        //                 break;
        //             }
        //     }
        // b = bb;
        while ((b | a) != b) b++;
        res = min(res, min(b - a, calc(a | b, b)) + b - bb);
        cout << res << "\n";
    }
    return 0;
}