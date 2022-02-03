#include <bits/stdc++.h>
 
using namespace std;

int a[2000005];
int n; 

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        a[i] = i;
    for(int i = 2; i <= n; i++) {
        for(int j = n / i * i + 2 * i - 1 ; j > i; j -= i)
            a[min(j, i + n - 1)] = a[j - i];
    }
    for(int i = 1; i <= n; i++)
        cout << a[i + n - 1] << " ";
}