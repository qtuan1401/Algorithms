#include <bits/stdc++.h>
using namespace std;
int dp[26][3001+201][3001+201],n,m,res;
char a[3001][201];
main()
{
   // freopen("test.inp","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",a[i]);
        for(int j=m;j>=1;j--)
            a[i][j]=a[i][j-1];
    //    cout <<endl;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if (a[i][j]!='.')
            {
                int x=i,y=j;
                while (x<n  && y<m)
                {
                    x++;
                    y++;
                    if (a[x][y]==a[i][j])
                    {
                        res+=dp[a[i][j]-'a'][i+j][x+y];
                        dp[a[i][j]-'a'][i+j][x+y]++;
                    }
                }
            }
    printf("%d",res);

}
