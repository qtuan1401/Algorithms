#include <bits/stdc++.h>

using namespace std;
int id,a[100000],b[100000],dp[2][10005],n;
void enter()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> a[i] >> b[i];
}
void solve()
{
    id=0;
    for(int i=0;i<=(n/2)+1;i++)
        dp[id][i]=INT_MAX-200001;
    dp[1-id][n/2+1]=INT_MAX-200000;
    dp[0][0]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=(n>>1);j++)
            dp[1-id][j]=min(INT_MAX-200001,min(dp[id][j+1]+a[i],dp[id][j-1]+b[i]));
        dp[1-id][0]=dp[id][1]+a[i];
        id=1-id;
    }
}
void print()
{
    cout << dp[id][0];
}
main()
{
    enter();
    solve();
    print();
}
