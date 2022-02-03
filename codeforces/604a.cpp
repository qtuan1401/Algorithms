#include <bits/stdc++.h>

using namespace std;
     
const int c[5] = {500, 1000, 1500, 2000, 2500}; 

int m[10], w[10];

int main() {
    for (int i = 0; i < 5; i++)
        cin >> m[i];
    for (int i = 0; i < 5; i++)
        cin >> w[i];
    int s, u;
    cin >> s >> u;
    int res = 100 * s - 50 * u;
    for (int i = 0; i < 5; i++)
        res += max(c[i] - c[i] * m[i] / 250 - 50 * w[i], c[i] / 10 *3);
    cout << res;
}