#include <bits/stdc++.h>
using namespace std;
#define md int(1e3)+1
#define LOW -(1e18)
long long dp[md],res;
int n,a[md][md];
main()
{
    //freopen("test.inp","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    for(int i=1;i<=n;i++)
        dp[1]+=a[i][i];
    res=dp[1];
    for(int i=2;i<=n;i++)
        dp[i]=LOW;
    for(int i=2;i<=n;i++)
    {
        for(int j=i-1;j>=1;j--)
        {
            dp[i]=max(dp[i],dp[j]-a[j][1]+a[j][i]+a[i][1]-a[i][i]);
        }
        res=max(res,dp[i]);
    }
    printf("%lld",res);
}
