#include <bits/stdc++.h>
#define task "test"
#define fi task".inp"
#define fo task".out"
#define forr(i,a,b) for(int i=(a);i<=(b);i++)
#define forl(i,a,b) for(int i=(a);i>=(b);i--)
#define maxN int(1e6)+1
#define INF int(2e9)+7
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
bool dd[maxN];
vector<ii> adj[maxN];
int b,d[maxN];
int n,m,a[maxN],k;
void dijkstra(int s)
{
    min_heap(ii) heap;
    int du,uv,v,u;
    heap.push(ii(0,s));
    forr(i,0,n)
        d[i]=INF;
    d[s]=0;
    while(heap.size())
    {
        u=heap.top().second;
        du=heap.top().first;
        heap.pop();
        if (du!=d[u])
            continue;
        int r=adj[u].size();
        if (r==0)
            continue;
        forr(i,0,r-1)
        {
            //cout << u << " "<<v<<"\n";
            v=adj[u][i].second;
    //        v=(v+u)%a[1];
            uv=adj[u][i].first;
            if (d[v]>(du+uv))
            {
                d[v]=(du+uv);
                heap.push(ii(d[v],v));
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
            //adj[k+j].push_back(ii(a[i],k));
        }
    }
    n=a[1]-1;
}
main()
{
   // freopen("test.inp","r",stdin);
    scanf("%d",&n);
    forr(i,1,n)
        scanf("%d",&a[i]);
    //forr(i,0,n)
      //  adj[i].push_back(ii(0,0));
    prepare();
    dijkstra(0);
    scanf("%d",&m);
    forr(i,1,m)
    {
        scanf("%d",&b);
        if (b>=d[b%a[1]])
            printf("TAK\n");
        else
            printf("NIE\n");
    }
}
