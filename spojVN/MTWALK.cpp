#include <bits/stdc++.h>

using namespace std;
int deltaX[4]={0,0,-1,1};
int deltaY[4]={-1,1,0,0};
bool visited[150][150];
int a[150][150],d,c,Min,Max,n;
typedef pair<int,int> ii;
ii Q[10001];
bool check(int i, int j)
{
    if(i>0 && i<=n && j>0 && j<=n && !visited[i][j] && a[i][j]>=d && a[i][j]<=c)
        return true;
    return false;
}
bool bfs()
{
    int l=1,r=0;
    if (a[1][1]>=d && a[1][1]<=c)
    {
        visited[1][1]=true;
        Q[++r]=ii(1,1);
    }
    while(l<=r)
    {
        ii Queue=Q[l++];
        int u=Queue.first,v=Queue.second;
        for(int i=0;i<4;i++)
        {
            int x=u+deltaX[i];
            int y=v+deltaY[i];
            if (check(x,y))
            {
               // cout << x << " " << y << endl;
                if (x==n && y==n) return true;
                visited[x][y]=true;
                Q[++r]=ii(x,y);
            }
        }
    }
    return false;
}
void prepare()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            visited[i][j]=false;
}
bool solve(int k)
{
    for(int i=Min;i<=Max-k;i++)
    {
        prepare();
        d=i;
        c=i+k;
        if (bfs()) return true;
    }
    return false;
}
void bs(int l,int r)
{
    while(r-l>1)
    {
        int Mid=(r+l)/2;
        if (solve(Mid))
        {
            r=Mid;
           // cout << l << " " << r <<" " <<l-r <<endl;
        }
        else l=Mid;
        //if (r-l>1) ;
    }
    cout << r;
}
main()
{
    cin >> n;Min=120;
    Max=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            cin >> a[i][j];
            Max=max(Max,a[i][j]);
            Min=min(Min,a[i][j]);
        }
    bs(-1,Max-Min);
}
