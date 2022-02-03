#include <bits/stdc++.h>

using namespace std;

int f[50], n;
bool isFib[1005];

int main() {
    cin >> n;
    f[1] = 1;
    f[2] = 2;
    isFib[1] = isFib[2] = 1;
    for(int i = 3; i <= 20; i++) {
        f[i] = f[i - 1] + f[i - 2];
        if (f[i] > n)
            break;
        //cout << f[i] << 
        isFib[f[i]] = 1;
    }
    for(int i = 1; i <= n; i++)
        cout << (isFib[i] ? 'O' : 'o'); 

    return 0;
}