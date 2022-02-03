#include <bits/stdc++.h>
#define task "test"
#define fi task".inp"
#define fo task".out"
#define forr(i,a,b) for(int i=(a);i<=(b);i++)
#define forl(i,a,b) for(int i=(a);i>=(b);i--)
#define maxN int(1e7)+1
#define INF int(1e9)
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
struct Node
{
    int lazy;
    int val;
} node[maxN];
int n,m,k;
void down(int id)
{
    int t=node[id].lazy;
    node[2*id].lazy+=t;
    node[2*id].val+=t;
    node[2*id+1].lazy+=t;
    node[2*id+1].val+=t;
    node[id].lazy=0;
}
void update(int id,int l,int r,int u,int v,int val)
{
    if (v<l || r<u)
    {
        return;
    }
    if (u<=l && v>=r)
    {
        node[id].val+=val;
 //       return;
        node[id].lazy+=val;
        return;
    }
    int mid=(l+r)/2;
    down(id);
    update(id*2,l,mid,u,v,val);
    update(id*2+1,mid+1,r,u,v,val);
    node[id].val=max(node[id*2].val,node[id*2+1].val);
}
int get(int id,int l,int r,int u,int v)
{
    if (v<l || u>r)
    {
        return -INFINITY;
    }
    if (u<=l && v>=r)
    {
        return node[id].val;
    }
    int mid=(l+r)/2;
    down(id);
    return max(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}
main()
{
  //  freopen(fi,"r",stdin);
//    freopen(fo,"w",stdout);
    scanf("%d%d",&n,&m);
    forr(i,1,m)
    {
        scanf("%d",&k);
        if (!k)
        {
            int x,y,v;
            scanf("%d%d%d",&x,&y,&v);
            update(1,1,n,x,y,v);
        }
        else
        {
            int x,y;
            scanf("%d%d",&x,&y);
            int res=0;
            res=get(1,1,n,x,y);
            printf("%d\n",res);
        }
    }
}

