#include <bits/stdc++.h>
using namespace std;
int a[301][301],c[301],r[301],x[301][301],y[301][301],c1,r1,ans,n;
main()
{
   // freopen("test.inp","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            int k;
            scanf("%d",&k);
            a[i][j]=k;
         //   x[i][j]=x[i-1][j]+k;
           // y[i][j]=y[i][j-1]+k;
        }
     for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            c[i]+=a[i][j];
    for(int j=1;j<=n;j++)
        for(int i=1;i<=n;i++)
            r[j]+=a[i][j];
    /*for(int i=1;i<=n;i++)
        cout << c[i] << " ";
    cout <<endl;
    for(int i=1;i<=n;i++)
        cout << r[i] << " ";
    cout <<endl;*/
    int ans=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if (ans<c[i]+r[j]-2*a[i][j])
            {
                c1=i;
                r1=j;
                ans=c[i]+r[j]-2*a[i][j];
              //  cout <<c1 << " "<<r1 <<" "<<res<<" "<<" "<<c[i]+r[j] << " "<<a[i][j]<<"\n";
            }
  //  int x,y;
    /*for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if (i!=c1 && j!=r1)
            {
                int res1=c[i]+r[j]-2*a[i][j];
                res1-=(a[c1][j]+a[i][r1]);
                if (res+res1>ans)
                {
                    ans=res+res1;
          //          x=i;
        //            y=j;
                }
            }*/
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
        {
            int u=r[1]-2*a[i][1]-a[j][1];
            int v=c[i]+c[j];
            for(int t=2;t<=n;t++)
            {
                ans=max(ans,r[t]+u+v-a[i][t]-2*a[j][t]);
                u=max(u,r[t]-2*a[i][t]-a[j][t]);
            }
            u=r[n]-2*a[i][n]-a[j][n];
            for(int t=n-1;t>=1;t--)
            {
                ans=max(ans,r[t]+u+v-a[i][t]-2*a[j][t]);
                u=max(u,r[t]-2*a[i][t]-a[j][t]);
            }
        }
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
        {
            int u=r[1]-2*a[i][1]-a[j][1];
            int v=c[i]+c[j];
            for(int t=2;t<=n;t++)
            {
                ans=max(ans,r[t]+u+v-a[i][t]-2*a[j][t]);
                u=max(u,r[t]-2*a[i][t]-a[j][t]);
            }
            u=r[n]-2*a[i][n]-a[j][n];
            for(int t=n-1;t>=1;t--)
            {
                ans=max(ans,r[t]+u+v-a[i][t]-2*a[j][t]);
                u=max(u,r[t]-2*a[i][t]-a[j][t]);
            }
        }
    for(int i=1;i<=n;i++)
    {
        for(int j1=1;j1<=n-1;j1++)
            for(int j2=j1+1;j2<=n;j2++)
                ans=max(ans,c[i]+r[j1]-2*a[i][j1]+r[j2]-2*a[i][j2]);
    }
    for(int j=1;j<=n;j++)
    {
        for(int i1=1;i1<=n-1;i1++)
            for(int i2=i1+1;i2<=n;i2++)
                ans=max(ans,r[j]+c[i1]-2*a[i1][j]+c[i2]-2*a[i2][j]);
    }
    // cout <<x << " " <<y <<endl;
    printf("%d",ans);
}
