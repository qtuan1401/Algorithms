#include <bits/stdc++.h>

using namespace std;

int T;
int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> T;
    while (T--) {
        cin >> n;
        int cnt = 0;
        for(int i = 0; i < 30; i++) 
            cnt += (((n >> i) & 1) == 1);
        cout << (1 << cnt) << '\n';
    }
    return 0;
}