#include <bits/stdc++.h>

using namespace std;

bool marked[305];
int p, n;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> p >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        x %= p;
        if (marked[x]) {
            cout << i + 1;
            return 0;
        } 
        marked[x] = true;
    }
    cout << -1;
    return 0;
}