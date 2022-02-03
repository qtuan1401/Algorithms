#include <bits/stdc++.h>

using namespace std;

int n;

int main(){
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i < n; i++) 
        cout << char(i % 4 + 'a');
    return 0;
}