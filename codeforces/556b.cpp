#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    int pre = -1;
    for(int i = 0; i < n; i++) {
        int x;
        int cur = 0;
        cin >> x;
        if (i % 2 == 0) {
            if (i > x)
                cur = i - x;
            else 
                cur = (n - 1) - x + (i + 1);
            if (pre == -1)
                pre = cur;
            else if (pre != cur) {
                cout << "No";
                return 0;
            }
        } else {
            if (i < x)
                cur = x - i;
            else
                cur = x + n - i; 
            if (cur != pre) {
                cout << "No";
                return 0;
            }
        }
    }
    cout << "Yes";
    return 0;
}