#include <bits/stdc++.h>

using namespace std;

vector < int > f;

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector < int > h(n);
    f.resize(n);
    for (int i = 0; i < n; i++)
        cin >> h[i];
    f[1] = abs(h[1] - h[0]);
    f[2] = min(abs(h[2] - h[0]), f[1] + abs(h[2] - h[1]));   
    for (int i = 3; i < n; i++)
        f[i] = min(f[i - 1] + abs(h[i] - h[i - 1]), f[i - 2] + abs(h[i] - h[i - 2]));
    cout << f[n - 1];
    return 0;
}