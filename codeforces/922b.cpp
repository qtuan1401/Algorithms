#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n, res = 0; 
    cin >> n;
    for(int a = 1; a <= n; a++)
        for(int b = a; b <= n; b++) {
            int c = 0 ^ (a ^ b);
            if (a <= b && b <= c && c <= n) {
                if (a + b > c)
                    res++;
            }
        }
    cout << res;
    return 0;
}