 #include <bits/stdc++.h>
#define task "tick"
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
#define HEAP(type) priority_queue<type>
#define min_heap(type) priority_queue<type,vector<type>,greater<type> >
struct node
{
    float w;
    int x;
    node(float a=0,int b=0)
    {
        w=a;
        x=b;
    }
};
bool operator<(node a,node b)
{
    return (a.w>b.w);
}

float d[maxN];
vector<int> p[maxN];
vector<node> adj[maxN];
int x[maxN],y[maxN],s[maxN],n;
bool visited[maxN];
float calc(int i,int j)
{
    return sqrt(pow(x[i]-x[j],2)+pow(y[i]-y[j],2));
}
void prepare()
{
    forr(i,1,n)
    {
      //  cout << i<< "\n";
        forr(j,0,p[i].size()-1)
        {
            int v=p[i][j];
          //  cout << v << " "<<calc(i,v)<<"\n";
            adj[i].push_back(node(calc(i,v),v));
        }
     //   cout << "\n";
    }
}
void dijkstra(int f)
{
    HEAP(node) heap;
    heap.push(node(0,f));
    int u,v;
    float du,uv;
    forr(i,1,n)
        d[i]=float(INF);
    d[f]=0;
    while(heap.size())
    {
        u=heap.top().x;
        du=heap.top().w;
        heap.pop();
        visited[u]=true;
        if (d[u]!=du)
            continue;

            forr(i,0,adj[u].size()-1)
            if (!visited[adj[u][i].x] && s[u]>0)
            {
                v=adj[u][i].x;
                uv=adj[u][i].w;
                if (d[v]>d[u])
                    s[u]--;
             //   cout << u<< " " <<v<< " " <<s[u]<<"\n";
              //  if (visited[v])
                //    continue;
                if (d[v]>du+uv)
                {
                   // s[u]--;
                    d[v]=du+uv;
                    heap.push(node(d[v],v));
                }
        }
    }
}
main()
{
    //freopen(fi,"r",stdin);
//    freopen(fo,"w",stdout);
    scanf("%d",&n);
    forr(i,1,n)
    {
        scanf("%d%d%d",&x[i],&y[i],&s[i]);
        forr(j,1,n-1)
        {
            int a;
            scanf("%d",&a);
            p[i].push_back(a);
        }
    }
    prepare();
    dijkstra(1);
    forr(i,1,n)
        printf("%.6f\n",d[i]);
}
