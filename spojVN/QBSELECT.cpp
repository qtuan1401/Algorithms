#include <bits/stdc++.h>
using namespace std;
int d[]={0, 1, 2, 4, 5, 8, 9, 10};
int n,a[10005][5],f[10005][10],res,Max=INT_MIN;
int getbit(int x,int i)
{
    return ((x>>i)&1);
}
main()
{
    //freopen("test.inp","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=4;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&a[j][i]),Max=max(Max,a[j][i]);
    if (Max<0)
    {
        printf("%d",Max);
        exit(0);
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=8;j++)
        {
            int sum=0;
            for(int k=1;k<=4;k++)
                sum+=getbit(d[j],k-1)*a[i][k];
            for(int k=1;k<=8;k++)
                if ((d[j] & d[k])==0)
                    f[i][j]=max(f[i][j],f[i-1][k]+sum);
        }
    for(int i=1;i<=8;i++)
        res=max(res,f[n][i]);
    printf("%d",res);
}
 