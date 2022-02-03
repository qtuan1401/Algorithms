#include <bits/stdc++.h>

using namespace std;

int d, m, pos;

int getBit(int x, int i) {
    return (x >> i) & 1;
}

int main() {
    //freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    
    while (T--) {
    //    cout << endl << endl;
        cin >> d >> m;
        long long res = 1, temp = 0;
        pos = -1;
        for(int i = 0; i < 30; i++)
            if (getBit(d, i))
                pos = i;
        for(int i = 0; i < 30; i++)
            if (getBit(d, i) && pos != i)
                res = (res + (1 << i)) % m;
        res++;
        for(int i = 0; i < pos; i++) 
            res *= ((1 << i) + 1), res %= m;
        cout << (res - 1 + m) % m << '\n';
    }
    return 0;
}