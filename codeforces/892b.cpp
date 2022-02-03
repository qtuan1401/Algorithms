#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector < int > h(n);
    for(int i = 0; i < n; i++) {
        int l;
        cin >> l;
        h[i] = i - l;
    }
    int cnt = 0;
    for(int i = n - 2; i >= 0; i--) {
        cnt += (h[i + 1] <= i);
        h[i] = min(h[i], h[i + 1]); 
        //cout << h[i] << " " << i << " " << h[i + 1] << endl;
    }
    cout << n - cnt;
    return 0;
}