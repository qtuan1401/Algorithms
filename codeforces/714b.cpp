#include <bits/stdc++.h>
using namespace std;

const int MXN = 1e5 + 10;

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector < int > a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    if (a.size() < 3)
        cout << "YES";
    else if (a.size( )== 3 && a[1] - a[0] == a[2]-a[1])
        cout << "YES";
    else 
        cout << "NO";
    return 0;
}