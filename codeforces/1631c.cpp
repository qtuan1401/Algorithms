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
        int n, k;
        cin >> n >> k;
        if (n == 4 && k == 3) {
            cout << "-1\n";
            continue;
        }
        int t = 0;
        vector < bool > marked(n, 0);
        n--;
        if (n == k) {
            cout << n << " " << 3 << '\n';
            cout << (n ^ 3) << " " << (n ^ 3) + 1 << '\n';
            cout << 2 << " " << 0 << '\n';
            marked[n] = marked[3] = marked[n ^ 3] = marked[(n ^ 3) + 1] = marked[2] = marked[0] = 1;
        } else {
            marked[k] = marked[n] = 1;
            cout << k << " " << n << '\n';
            if (!marked[n ^ k] && !marked[0]) {
                cout << 0 << " " << (n ^ k) << '\n';
                marked[0] = marked[n ^ k] = 1;
            }
        } 
        
        for (int i = 1; i < n; i++) {
            if (!marked[i]) {
                cout << i << " " << (n ^ i) << '\n';
                marked[i] = marked[n ^ i] = 1;
            }
        }
    }
    return 0;
}