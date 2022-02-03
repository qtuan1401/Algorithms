#include <bits/stdc++.h>
 
using namespace std;
 
long long n, k;
 
int bs(int l, int r) {
    while (l <= r) {
        int mid = (l + r) >> 1;
        long long candy = (n - mid) * (n - mid + 1) / 2 - mid;
        //cout << candy <<" "  << mid << endl;
        if (candy == k) 
            return mid;
        if (candy > k) 
            l = mid + 1;
        else r = mid - 1;
    }
    return 0;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    cout << bs(1, n);
    return 0;
}