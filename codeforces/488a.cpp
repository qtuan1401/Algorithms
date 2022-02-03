#include <bits/stdc++.h>
    
using namespace std;
    
int main() {
    ios_base::sync_with_stdio(0);
    int x, res = 1;
    cin >> x;
    while (to_string(x + res).find('8') == -1)
        res++;
    cout << res;
    return 0;
}