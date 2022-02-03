#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
lli a[100000],dp[100000],d,s,i,j,m,k,n,Max;
bool kt=false;
int main()
{
    cin >> n >> k;
    for(i=1;i<=n;i++) cin >> a[i];m=0;
    Max=0;
    for(i=1;i<=n;i++)
    {
        dp[i]=dp[i-1]+a[i];
        for(j=i-2;j>=i-k;j--)
            if (j>=0) dp[i]=max(dp[i],dp[j]+a[i]);
            else break;
        if (Max<dp[i]) Max=dp[i];
    }
    cout << Max;
    return 0;
}
