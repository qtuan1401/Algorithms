#include <bits/stdc++.h>

using namespace std;
int deltaX[4]={0,1,0,-1};
int deltaY[4]={1,0,-1,0};
int a[1000][1000],n,m,Max=INT_MIN,Count;
void dfs(int u,int v,int h)
{
    if (a[u][v]!=h) return;
    a[u][v]=h+1;
    for(int i=0;i<4;i++) dfs(u+deltaX[i],v+deltaY[i],h);
}
main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            cin >> a[i][j];
            Max=max(Max,a[i][j]);
        }
    for(int h=1;h<Max;h++)
    {
        for(int u=1;u<=m;u++)
        {
            dfs(1,u,h);
            dfs(n,u,h);
        }
        for(int u=2;u<n;u++)
        {
            dfs(u,1,h);
            dfs(u,m,h);
        }
        for (int u=2;u<n;u++)
            for(int v=2;v<m;v++)
                if (a[u][v]==h)
                {
                    a[u][v]=h+1;
                    Count++;
                }
    }
    cout <<Count;
}
