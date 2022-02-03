#include <bits/stdc++.h>

using namespace std;

const int MXN = 305;

int memo[MXN][MXN];

int f(int x, int y){
    if (!x && !y)
        return 0;
    if (memo[x][y] != -1)
        return memo[x][y];
    int res = 0;
    for(int i = 0; i < x; i++)
        res |= !f(i, y);
    for(int i = 0; i < y; i++)
        res |= !f(x, i);
    for(int i = 0; i < min(x, y); i++)
        res |= !f(x - i - 1, y - i - 1);
    return memo[x][y] = res;
}


int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector < int > a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    if (n == 1) {
        if (!a[0])
            cout << "BitAryo";
        else
            cout << "BitLGM";
    } else if (n == 2) {
        for(int i = 0; i < MXN; i++)
            for(int j = 0; j < MXN; j++)
                memo[i][j] = -1;
        if (f(a[0], a[1]))
            cout << "BitLGM";
        else
            cout << "BitAryo";
    } else {
        if (a[0] ^ a[1] ^ a[2])
            cout << "BitLGM";
        else
            cout << "BitAryo";
    }
    return 0;
}
