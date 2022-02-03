#include <bits/stdc++.h>

using namespace std;
unsigned long long int res,n,m;
int main()
{
    cin >> n >>m;
    res=n*m;
    while (res>n) res=res+(res-n-1)/(m-1)-n;
    cout << res;
    return 0;
}
