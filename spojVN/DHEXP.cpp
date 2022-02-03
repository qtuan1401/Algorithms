#include <iostream>
#include <algorithm>
using namespace std;
long n,i,k;
long long t;
int main()
{
    long a[100000];
    cin >> n >> k;
    for (i=1;i<=n;i++) cin >> a[i];
    sort(a+2,a+n+1);
    t=a[1];
    for (i=n;i>=n-k+1;i--)
        t=t+a[i];
    for (i=n-k;i>=2;i--)
        t=t-a[i];
    cout << t;
    return 0;
}

