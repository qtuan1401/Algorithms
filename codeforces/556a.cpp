#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, cnt = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        char c;
        cin >> c;
        cnt += (c == '1' ? 1 : -1);
    }
    cout << abs(cnt);
}