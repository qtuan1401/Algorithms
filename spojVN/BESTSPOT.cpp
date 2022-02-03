#include <bits/stdc++.h>
#define task "test"
#define fi task".inp"
#define fo task".out"
#define forr(i,a,b) for(int i=(a);i<=(b);i++)
#define forl(i,a,b) for(int i=(a);i>=(b);i--)
#define maxN int(1e5)+1
#define INF int(1e9)+1
#define Memset(a,value) memset(a,value,sizeof(a))
#define Forr(i,a) for(vector<int>:: iterator i=(a).begin();i!=(a).end();i++)
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef long long int lli;
typedef long long ll;
typedef unsigned long long int ulli;
#define max_heap(type) priority_queue<type>
#define min_heap(type) priority_queue<type,vector<type>,greater<type> >
int pos;
vector<ii> adj[maxN];
int d[maxN],dp[maxN],a[maxN],f,c,n;
int res=INF;
void dijkstra_heap(int s)
{
    min_heap(ii) heap;
    int du,uv,u,v;
    heap.push(ii(0,s));
    forr(i,1,n)
        d[i]=INF;
    d[s]=0;
    while(heap.size())
    {
        u=heap.top().second;
        du=heap.top().first;
        heap.pop();
     //   cout << u << " "<<v<<"\n";
        if (du!=d[u])
            continue;
        forr(i,0,adj[u].size()-1)
        {
            v=adj[u][i].second;
            uv=adj[u][i].first;
            if (d[v]>du+uv)
            {
                d[v]=du+uv;
              //  dp[v]=dp[u]+1;
                heap.push(ii(d[v],v));
            }
        }
    }
}
main()
{
   // freopen(fi,"r",stdin);
    //freopen(fo,"w",stdout);
    scanf("%d%d%d",&n,&f,&c);
    forr(i,1,f)
        scanf("%d",&a[i]);
    forr(i,1,c)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        adj[u].push_back(ii(w,v));
        adj[v].push_back(ii(w,u));
    }
    forr(i,1,n)
        adj[i].push_back(ii(0,0));
    forr(i,1,n)
    {
        int sum=0;
        dijkstra_heap(i);
        forr(i,1,f)
            if (d[a[i]]==INF)
                break;
            else sum+=d[a[i]];
        if ((res>sum) || (res==sum && pos>i))
        {
            res=sum;
            pos=i;
        }
    }
    printf("%d",pos);
}

