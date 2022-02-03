#include <bits/stdc++.h>
using namespace std;
#define md int(1e6)+5
struct node
{
    int i,j,type,id,val;
}a[md];
int n,m,q,t[md],res[md],pos[md];
bool cmp(const node& a,const node& b)
{
    return (a.j<b.j || (a.j==b.j && a.type<b.type));
}
inline int sum(int x)
{
    int res=0;
    while (x>0)
    {
        res+=t[x];
        x-=(x&(-x));
    }
    return res;
}
inline void update(int x,int val)
{
    while (x<=md)
    {
        t[x]+=val;
        x+=(x&(-x));
    }
}
main()
{
 //   freopen("test.inp","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i].i);
        a[i].j=i;
        a[i].type=-1;
    }
    scanf("%d",&q);
    for(int i=n+1;i<=n+q;i++)
    {
        scanf("%d%d",&a[i].i,&a[i].j);
        a[i].id=i;
    }
    m=n+q;
    sort(a+1,a+1+m,cmp);
    for(int i=1;i<=m;i++)
    {
        if (a[i].type)
        {
            update(a[i].j,1);
            if (pos[a[i].i]>0)
                update(pos[a[i].i],-1);
            pos[a[i].i]=a[i].j;
        }
        else res[a[i].id-n]=sum(a[i].j)-sum(a[i].i-1);
    }
    for(int i=1;i<=q;i++)
        printf("%d\n",res[i]);
}
