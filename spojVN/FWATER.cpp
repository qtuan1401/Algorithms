#include <bits/stdc++.h>
using namespace std;
#define md 305
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
int lab[md],n,r;
iii graph[3000005];
long long res;
inline int root(int x)
{
    while (lab[x]>-1)
        x=lab[x];
    return x;
}
inline void Union(int i,int j)
{
    int tmp=lab[i]+lab[j];
    if (lab[i]<lab[j])
    {
        lab[j]=i;
        lab[i]=tmp;
    }
    else
    {
        lab[i]=j;
        lab[j]=tmp;
    }
}
inline void kruksal()
{
    for(int i=0;i<=n;i++)
        lab[i]=-2;
    for(int i=1;i<=r;i++)
    {
        int u=graph[i].second.first;
        int v=graph[i].second.second;
        u=root(u);
        v=root(v);
        if (u!=v)
        {
            Union(u,v);
            res+=graph[i].first;
        }
    }
}
main()
{
    r=1;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int k;
        scanf("%d",&k);
        graph[r++]=iii(k,ii(0,i));
    }
 //   cout << n <<endl;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
         //   if (i!=j)
            {
           //     cout << i << " "<<j <<endl;
                int w;
                scanf("%d",&w);
                graph[r++]=iii(w,ii(i,j));
            }
    r--;
    sort(graph+1,graph+1+r);
    kruksal();
    printf("%lld",res);
}