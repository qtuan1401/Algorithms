#include <bits/stdc++.h>

using namespace std;

int n, a, b;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> a >> b;
    for(int i = 0; i <= n; i++)
        if (i % a == 0 && (n - i) % b == 0) {
            for(int j = 1; j <= i; j += a) {
                for(int k = 1; k <= a; k++)
                    cout << j + k % a << " ";
            }
            for(int j = i + 1; j <= n; j += b)
                for(int k = 1; k <= b; k++)
                    cout << j + k % b << " ";
            return 0;
        }
    cout << "-1";
    return 0;
}