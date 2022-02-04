#include <bits/stdc++.h>

using namespace std;

int getBit(int x, int i) {
    return (x >> i) & 1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector < int > id(n);
        int pos = 0;
        for (int i = 0; i < 20; i++)
            if (getBit(n - 1, i))
                pos = i;
        
        for (int i = n - 1; i >= 0; i--)
            if (getBit(i, pos))
                cout << i << " ";
        for (int i = 0; i < n; i++)
            if (!getBit(i, pos))
                cout << i << " ";
        cout << '\n';
    }
    return 0;
}