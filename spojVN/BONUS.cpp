#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
typedef long long ll;
ll i,j,n,k,a[10000][10000];
lli res=LONG_LONG_MIN;
int main()
{
    cin >> n >>k;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            cin >> a[i][j];
            a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
        }
    for(i=1;i<=n-k+1;i++)
        for(j=1;j<=n-k+1;j++)
            res=max(res,a[i+k-1][j+k-1]-a[i-1][j+k-1]-a[i+k-1][j-1]+a[i-1][j-1]);
    cout << res;
    return 0;
}
