#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define md int(1e5)+5
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
int n,t[md];
iii a[md];
inline void update(int x,int val)
{
    while (x<=n)
    {
        t[x]=min(t[x],val);
        x+=(x&(-x));
    }
}
inline int get(int x)
{
    int res=n+1;
    while (x>0)
    {
        res=min(res,t[x]);
        x-=(x&(-x));
    }
    return res;
}
main()
{
   // freopen("test.inp","r",stdin);
    scanf("%d",&n);
    int p;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&p);
        a[p].x=i;
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&p);
        a[p].y.x=i;
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&p);
        a[p].y.y=i;
    }
    for(int i=1;i<=n;i++)
        t[i]=n+1;
    sort(a+1,a+1+n);
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        int val=get(a[i].y.y);
        if (val>a[i].y.x)
            cnt++;
        update(a[i].y.y,a[i].y.x);
    }
    printf("%d",cnt);
}
