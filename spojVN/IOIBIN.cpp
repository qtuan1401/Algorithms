#include <bits/stdc++.h>
using namespace std;
#define md 10005
int lab[md],q;
inline int root(int x)
{
    while (lab[x]>0)
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
main()
{
    scanf("%d",&q);
    for(int i=1;i<=10000;i++)
        lab[i]=-1;
    for(int i=1;i<=q;i++)
    {
        int u,v,k;
        scanf("%d%d%d",&u,&v,&k);
        u=root(u);
        v=root(v);
        if (k==1)
        {
            if (u!=v)
            	Union(u,v);
        }
        else
        {
            if (u==v)
                printf("1\n");
            else
                printf("0\n");
        }
    }
}
