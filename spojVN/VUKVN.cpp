#include <bits/stdc++.h>
using namespace std;
#define md 505
#define INF 2505
typedef pair<int,int> ii;
int n,m,d[md][md];
char s[md][md];
bool vis[md][md];
queue<ii> q;
int dx[]={0,0,1,-1};
int dy[]={-1,1,0,0};
ii s1,f;
/*
     -1,0
0,-1 0,0 0,1
     1,0
*/
inline void bfs()
{
    while (q.size())
    {
        ii val=q.front();
        int u=val.first;
        int v=val.second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int uu=u+dx[i];
            int vv=v+dy[i];
            if (uu<1 || uu>n || vv<1 || vv>m)
                continue;
            if (d[uu][vv]>d[u][v]+1)
            {
                d[uu][vv]=d[u][v]+1;
                q.push(ii(uu,vv));
            }
        }
    }
}
inline bool check(int mid,int u,int v)
{
    vis[u][v]=true;
   // cout <<u << " " <<v << endl;
    for(int i=0;i<4;i++)
    {
        int uu=u+dx[i];
        int vv=v+dy[i];
        if (uu<1 || uu>n || vv<1 || vv>m)
            continue;
        if (!vis[uu][vv] && d[uu][vv]>=mid)
            check(mid,uu,vv);
    }
    if (!vis[f.first][f.second])
        return false;
    else return true;
}
inline int bs(int l,int r)
{
    int pos=0;
    while (l<=r)
    {
        int mid=(l+r)>>1;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                vis[i][j]=false;
       // cout << mid<<" " <<l<<" "<<r <<endl;
        if (check(mid,s1.first,s1.second))
        {
            //cout <<mid <<endl;
            pos=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    return pos;
}
main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            d[i][j]=INF;
  //  scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",s[i]+1);
        for(int j=1;j<=m;j++)
            if (s[i][j]=='+')
            {
                q.push(ii(i,j));
                d[i][j]=0;
            }
            else if (s[i][j]=='V')
            {
                s1=ii(i,j);
            }
            else if (s[i][j]=='J')
            {
                f=ii(i,j);
            }
    }
    bfs();
    printf("%d",bs(1,d[s1.first][s1.second]));
   // printf("%d",pos);
}
