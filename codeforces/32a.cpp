#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, d;
    cin >> n >> d;
    vector < int > a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int res = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if (i != j)
                res += (abs(a[i] - a[j]) <= d);
    cout << res;
    return 0;
}