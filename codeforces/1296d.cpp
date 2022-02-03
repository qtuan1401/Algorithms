#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, a, b, k;
    ios_base::sync_with_stdio(0);
    cin >> n >> a >> b >> k;
    vector < int > ans(n);
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ans[i] = ((x - 1) % (a + b)) / a;
    }
    sort(ans.begin(), ans.end());
    int cnt = 0;
    for(int i = 0; i < n; i++, cnt++) {
        k -= ans[i];
        if (k < 0)
            break;
    }
    cout << cnt;
    return 0;
}