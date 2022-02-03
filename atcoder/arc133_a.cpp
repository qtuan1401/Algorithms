#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector < int > a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int x = a[n - 1];
    for (int i = 0; i + 1 < n; i++)
        if (a[i] > a[i + 1]) {
            x = a[i];
            break;
        }

    for (int i = 0; i < n; i++)
        if (a[i] != x)
            cout << a[i] << " ";
}