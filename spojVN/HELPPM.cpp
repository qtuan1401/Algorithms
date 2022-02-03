#include <bits/stdc++.h>

using namespace std;
int dp[1000][1000];
int x1,y3,x2,y2,n,m,Max,k;
main()
{
    cin >> n >> m >>k;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            cin >> dp[i][j];
            dp[i][j]=dp[i][j]+dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
        }
    int Max=n*m-1;
    if (dp[n][m]<k)
    {
        cout << -1;
        return 0;
    }
    for(int i=1;i<=n;i++)
        for(int x=i;x<=n;x++)
        {
            int j=1,y=1;
            while (y<=m && j<=y)
            {
                int s=dp[x][y]-dp[i-1][y]-dp[x][j-1]+dp[i-1][j-1];
                if (s>=k)
                {
                    int z=(x-i+1)*(y-j+1);
                    if (Max>z)
                    {
                        Max=z;
                        x1=i;
                        y3=j;
                        x2=x;
                        y2=y;
                    }
                    j++;
                }
                else y++;
            }
        }
    if (Max==n*m+1) cout << -1;
    else
    {
        cout << Max << "\n";
        cout << x1 << " " << y3 << " " << x2 << " "<<y2;
    }
}
