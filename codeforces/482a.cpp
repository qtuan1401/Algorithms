#include <bits/stdc++.h>
 
using namespace std;
 
int n, k;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    cout << 1 << " ";
    for(int i = k, num  = 1, sign = 1; i >= 1; i--) {
        num += sign * i;
        sign *= -1;
        cout << num << " ";
    }
    for(int i = k + 2; i <= n; i++)
        cout << i << " ";
	return 0;
}