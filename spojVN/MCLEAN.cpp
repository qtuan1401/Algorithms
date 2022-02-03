#include <bits/stdc++.h>
#define task "test"
#define fi task".inp"
#define fo task".out"
#define forr(i,a,b) for(int i=(a);i<=(b);i++)
#define forl(i,a,b) for(int i=(a);i>=(b);i--)
#define maxN int(25)+1
#define INF int(1e9)+7
#define Memset(a,value) memset(a,value,sizeof(a))
#define Forr(i,a) for(vector<int>:: iterator i=(a).begin();i!=(a).end();i++)
using namespace std;
typedef long long int lli;
typedef long long ll;
typedef unsigned long long int ulli;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
#define max_heap(type) priority_queue<type>
#define min_heap(type) priority_queue<type,vector<type>,greater<type> >
struct node
{
    int x,y,val;
}b[11];
queue<node> Queue;
int deltaX[4]={0,0,1,-1};
int deltaY[4]={1,-1,0,0};
int dis[11][11];
int dis2[11],x,y;
char a[25][25];
int dp[1<<10][11];
bool visited[25][25];
int n,m;
inline int bfs(int u,int v,int x,int y)
{
    while(!Queue.empty())
        Queue.pop();
    Memset(visited,false);
    node tmp2;
    tmp2.x=u;
    tmp2.y=v;
    tmp2.val=0;
    visited[u][v]=true;
    Queue.push(tmp2);
    while(Queue.size())
    {
        node tmp=Queue.front();
        Queue.pop();
        if (tmp.x==x && tmp.y==y)
        {
            return tmp.val;
        }
        forr(i,0,3)
        {
            int xx=tmp.x+deltaX[i];
            int yy=tmp.y+deltaY[i];
            if (xx<1 || xx> n || yy<1 || yy>m)
                continue;
            if (a[xx][yy]=='x' || visited[xx][yy])
                continue;
            node tmp1;
            tmp1.x=xx;
            tmp1.y=yy;
            visited[xx][yy]=true;
            tmp1.val=tmp.val+1;
            Queue.push(tmp1);
        }
    }
    return -1;
}
main()
{
    //freopen("test.inp","r",stdin);
  	bool res;
    while (cin>>m>>n)
    {
        int r=0;
        res=true;
        //scanf("%d%d",&m,&n);
        //cin >> n >> m;
        if (n==0 && m==0)
        {
            exit(0);
        }
        //cout << n <<" " << m<<"\n";
        //getchar();
        forr(i,1,n)
            forr(j,1,m)
            {
                cin >> a[i][j];
          //      cout << a[i][j];
                if (a[i][j]=='o')
                {
                    y=j;
                    x=i;
                }
                else if (a[i][j]=='*')
                {
                    b[r].x=i;
                    b[r++].y=j;
                }
          //         getchar();
            }
        forr(i,0,r-1)
        {
            dis2[i]=bfs(x,y,b[i].x,b[i].y);
          //  cout << dis2[i]<< "\n";
            if (dis2[i]==-1)
            {
                res=false;
                break;
            }
        }
        if (!res)
        {
            printf("-1\n");
            continue;
        }
        r;
        forr(i,0,r-1)
            forr(j,i+1,r-1)
                dis[i][j]=dis[j][i]=bfs(b[i].x,b[i].y,b[j].x,b[j].y);
        int state=(1<<r)-1;
        Memset(dp,INF);
        forr(i,0,r)
            dp[1<<i][i]=dis2[i];
        forr(i,1,state)
            forr(j,0,r)
            {
                if (!((1<<j)&i))
                    continue;
                forr(k,0,r)
                {
                    if ((k==j) || ((1<<k)&i))
                        continue;
                    int s=i+(1<<k);
                    dp[s][k]=min(dp[s][k],dp[i][j]+dis[j][k]);
                }
            }
        int ans=INF;
        forr(i,0,r)
            ans=min(ans,dp[state][i]);
        printf("%d\n",ans);
    }
}
