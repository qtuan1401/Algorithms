#include <bits/stdc++.h>
using namespace std;
long long m,n,t,a[1000000],dp[1000000];
main()
{
    //freopen(fi,"r",stdin);
    //freopen(fo,"w",stdout);
    cin >> m >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        t+=a[i];
    }
    memset(dp,0,sizeof(dp));
    dp[t]=0;dp[0]=1;
    for(int i=1;i<=n;i++)
        for(int j=m;j>=a[i];j--)
            dp[j]=dp[j] | dp[j-a[i]];
    //int i;
    for(int i=m;i>=1;i--)
        if (dp[i]==1)
        {
            cout << i;
            break;
        }
    //cout << i;
}

