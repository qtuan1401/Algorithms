#include<bits/stdc++.h>

using namespace std;

int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == 1) {
            cout << "-1";
            return 0;
        }
    }
    cout << 1;
    return 0;
}