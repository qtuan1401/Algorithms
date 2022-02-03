#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int x, y;
    cin >> x >> y;
    
    int x1 = y - 1;
    if (y == 0)
        cout << "NO";
    else if (y == 1)
    else if (x < x1) 
        cout << "NO";
    else if ((x - x1) % 2 == 0)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}