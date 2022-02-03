#include <bits/stdc++.h>

using namespace std;
long dp[10000][10000],a[10000][10000],n,m,i,j,Max;
int main()
{
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++) scanf("%d",&a[i][j]);
    for(i=0;i<=n+1;i++) dp[i][1]=1;
    for(j=0;j<=m+1;j++) dp[1][j]=1;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if (a[i][j]==a[i-1][j] && a[i][j]==a[i-1][j-1] && a[i][j-1]==a[i][j]) dp[i][j]=min(dp[i][j-1],min(dp[i-1][j-1],dp[i-1][j]))+1;
            else dp[i][j]=1;
    Max=1;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if (Max<dp[i][j]) Max=dp[i][j];
    printf("%d", Max);
    return 0;
}
