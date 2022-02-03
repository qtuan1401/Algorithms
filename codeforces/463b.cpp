#include <bits/stdc++.h>

using namespace std;

int n;
int h[100005];

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> h[i];
    int cur = 0;
    long long res = 0;
    for(int i = 0; i < n; i++) {
        if (cur + h[i] - h[i + 1] < 0)
            res -= cur + h[i] - h[i + 1];
        cur = max(0, cur + h[i] - h[i + 1]);
    }
    cout << res;
    return 0;
}