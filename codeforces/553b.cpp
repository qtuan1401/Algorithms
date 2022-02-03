#include <bits/stdc++.h>

using namespace std;

int n; 
long long f[55];
long long k;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    f[0] = f[1] = 1;
    for(int i = 2; i < 55; i++) 
        f[i] = f[i - 1] + f[i - 2];

    for(int i = 0; i < n; i++) 
        if (k <= f[n - i - 1])
            cout << i + 1 << " ";
        else {
            cout << i + 2 << " " << i + 1 << " ";
            k -= f[n - ++i];
        }
}
     