#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    vector < int > a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int res = 1e9, num = 0;
    for(int i = 1; i <= 100; i++) {
        int diff = 0;
        for(int j = 0; j < n; j++)
            if (abs(a[j] - i) > 1)
                diff += abs(a[j] - i) - 1;
        if (res > diff) {
            res = diff;
            num = i;
        }
    }
    cout << num << " " << res;
    return 0;
}