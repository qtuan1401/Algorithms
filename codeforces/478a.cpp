#include <bits/stdc++.h>

using namespace std;
 
int main() {
    int a1, a2, a3, a4, a5, sum = 0;
    cin >> a1 >> a2 >> a3 >> a4 >> a5;
    sum = a1 + a2 + a3 + a4 + a5;
    if (sum % 5 || sum == 0) 
        cout << "-1";
    else
        cout << sum / 5;
    return 0;
}