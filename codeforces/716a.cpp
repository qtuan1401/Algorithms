#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, c;
    cin >> n >> c;
    vector < int > a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int res = 1;
    for(int i = 1; i < n; i++)
        if (a[i] - a[i - 1] <= c)
            res++;
        else 
            res = 1;
    cout << res;
    return 0;
}