#include <bits/stdc++.h>
#define task "test"
#define fi task".inp"
#define fo task".out"
#define forr(i,a,b) for(int i=(a);i<=(b);i++)
#define forl(i,a,b) for(int i=(a);i>=(b);i--)
#define maxN int(1e6)+1
#define INF (long long)(2e18)+10
#define Memset(a,value) memset(a,value,sizeof(a))
#define Forr(i,a) for(vector<int>:: iterator i=(a).begin();i!=(a).end();i++)
using namespace std;
typedef long long int lli;
typedef long long ll;
typedef unsigned long long int ulli;
typedef pair<ll,int> ii;
typedef pair<int,ii> iii;
#define max_heap(type) priority_queue<type>
#define min_heap(type) priority_queue<type,vector<type>,greater<type> >
bool dd[maxN],visited[maxN];
vector<ii> adj[maxN];
ll d[maxN];
int n,m,a[maxN],k;
ll h;
void dijkstra()
{
    min_heap(ii) heap;
    ll du,uv;
    int v,u;
    heap.push(ii(1,1));
    forr(i,0,n)
        d[i]=INF;
    d[1]=1;
    visited[1]=true;
    while(heap.size())
    {
        u=heap.top().second;
        du=heap.top().first;
        visited[u]=false;
        heap.pop();
        //if (du!=d[u])
          //  continue;
        int r=adj[u].size();
        if (r==0)
            continue;
        forr(i,0,r-1)
        {
            //cout << u << " "<<v<<" "<<du <<" "<<uv<<"\n";
            //if(du<0) break;
            v=adj[u][i].second;
    //        v=(v+u)%a[1];
            uv=adj[u][i].first;
            if (d[v]>(du+uv))
            {
                d[v]=(du+uv);
                if (!visited[v])
                {
                    heap.push(ii(d[v],v));
                    visited[v]=true;
                }
            }
        }
    }
}
void prepare()
{
    forr(i,2,n)
    {
        k=a[i]%a[1];
        if (dd[k]) continue;
        dd[k]=true;
        forr(j,0,a[1]-1)
        {
            adj[j].push_back(ii(a[i],(k+j)%a[1]));
        }
    }
            //adj[k+j].push_back(ii(a[i],k));
    n=a[1]-1;
}
main()
{
   // freopen("test.inp","r",stdin);
    scanf("%lld",&h);
    n=3;
    forr(i,1,n)
        scanf("%d",&a[i]);
    //forr(i,0,n)
      //  adj[i].push_back(ii(0,0));
    sort(a+1,a+1+n);
    if (a[1]==1)
    {
        printf("%lld",h);
        exit(0);
    }
    prepare();
    dijkstra();
    lli res=0;
    forr(i,0,a[1]-1)
    {
      //  cout << d[i]<<"\n";
        if (d[i]<=h)
            res+=(h-d[i])/a[1]+1;
    }
    printf("%lld",res);
}
