#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n, sum = 0, i = 0;
    cin >> n;
    while (n >= 0) {
        i++;
        sum += i;
        n -= sum;
    }
    cout << i - 1;
    return 0;
}