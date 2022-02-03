#include <bits/stdc++.h>

using namespace std;

int c[5];
int res = 300;

bool check(int a, int b, int c) {
    return (a + b > c && a + c > b && b + c > a);
}

int main() {
    cin >> c[1] >> c[2] >> c[3];
    sort(c + 1, c + 4);
    for(int a = c[1]; a <= c[3]; a++)
        for(int b = c[2]; b <= c[3]; b++)
            if (check(a, b, c[3]))
                res = min(res, a - c[1] + b - c[2]);
    cout << res;
    return 0;
}