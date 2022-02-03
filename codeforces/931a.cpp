#include <bits/stdc++.h>

using namespace std;

long long a, b;

int main() {
    cin >> a >> b;
    if (b < a)
        swap(a, b);
    long long dist = (b - a) / 2;
    //cout << dist << endl;
    long long res = dist * (dist + 1);
    if ((b - a) % 2 != 0)
        res += dist + 1;
    cout << res;
    return 0;
}