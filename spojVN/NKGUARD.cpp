#include <bits/stdc++.h>

using namespace std;
int deltaX[8]={-1,-1,0,1,1,1,0,-1};
int deltaY[8]={0,1,1,1,0,-1,-1,-1};
int a[1005][1005],Free[1005][1005],n,m,res=0;
bool check;
void dfs(int u,int v)
{
    Free[u][v]=false;
    for(int i=0;i<8;i++)
    {
        int x=u+deltaX[i];
        int y=v+deltaY[i];
        if (x>0 && x<=n && y>0 && y<=m)
        {
            if (check && a[x][y]>a[u][v])
                check=false;
            if (Free[x][y] && a[x][y]==a[u][v])
                dfs(x,y);
        }
    }
}
main()
{
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin >> a[i][j];
    for(int i=1;i<=n;i++)
    {
    	for(int j=1;j<=m;j++) Free[i][j]=true;
    }
    for(int i=1;i<=n;i++) 
        for(int j=1;j<=m;j++)
            if (Free[i][j])
            {
                check=true;
                dfs(i,j);
                if (check)
                    res++;
            }
    cout << res;
}
