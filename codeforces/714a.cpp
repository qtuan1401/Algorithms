#include <bits/stdc++.h>
    
using namespace std;
    

int main() {
    ios_base::sync_with_stdio(0);
    long long l1, r1, l2, r2, k;
    cin >> l1 >> r1 >> l2 >> r2 >> k;
    l1 = max(l1, l2); r1 = min(r1, r2);
    cout << max(r1 - l1 + (k > r1 || k < l1), 0ll);
    return 0;
}