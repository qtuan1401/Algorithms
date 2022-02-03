#include <bits/stdc++.h>
using namespace std;
typedef pair<int,pair<int,int> > iii;
#define md 3*int(1e5)+5
#define Max int(1e5)+1
struct node
{
    int a,h,vt;
} a[md];
int n,t[md],b[md];
inline int sum(int m)
{
    int res=0;
    while (m>0)
    {
        res+=t[m];
        m-=(m&(-m));
    }
    return res;
}
inline void update(int m,int val)
{
    while (m<=Max)
    {
        t[m]+=val;
        m+=(m&(-m));
    }
}
bool operator < (node a,node b)
{
    return (a.h<b.h || (a.h==b.h && a.a<b.a));
}
main()
{
 //   freopen("test.inp","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&a[i].a,&a[i].h);
    for(int i=1;i<=n;i++)
        a[i].vt=i;
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
    {
        if (a[i].a>a[i-1].a || a[i].h>a[i-1].h)
            b[a[i].vt]=sum(a[i].a);
        else b[a[i].vt]=b[a[i-1].vt];
        update(a[i].a,1);
    }
    for(int i=1;i<=n;i++)
        printf("%d\n",b[i]);
}
