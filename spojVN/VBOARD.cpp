#include <bits/stdc++.h>
using namespace std;
#define md 501
int sw[md][md],sb[md][md];
int k,n,q;
main()
{
    //freopen("test.inp","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&k);
            if ((i+j)&1)
                sw[i][j]=k;
            else sb[i][j]=k;
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            sw[i][j]+=(sw[i-1][j]+sw[i][j-1]-sw[i-1][j-1]);
            sb[i][j]+=(sb[i-1][j]+sb[i][j-1]-sb[i-1][j-1]);
        }
    scanf("%d",&q);
    while(q--)
    {
        int x,y,x2,y2;
        scanf("%d%d%d%d",&x,&y,&x2,&y2);
        int w=sw[x2][y2]-sw[x2][y-1]-sw[x-1][y2]+sw[x-1][y-1];
        int b=sb[x2][y2]-sb[x2][y-1]-sb[x-1][y2]+sb[x-1][y-1];
        printf("%d\n",abs(w-b));
    }
}

