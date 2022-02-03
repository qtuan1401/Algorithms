#include <bits/stdc++.h>
using namespace std;
#define md int(1e5)+5
int res,n,a[md],f[md],t[md],c[md];
pair<int,int> b[md];
inline void update(int x,int val)
{
    while (x<=n)
    {
        t[x]=max(t[x],val);
        x+=(x&(-x));
    }
}
inline int sum(int x)
{
    int res=0;
    while (x>0)
    {
        res=max(res,t[x]);
        x-=(x&(-x));
    }
    return res;
}
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        b[i].first=a[i];
        b[i].second=i;
    }
    sort(b+1,b+1+n);
    int cnt=1;
    c[b[1].second]=1;
    for(int i=2;i<=n;i++)
    {
        if (b[i].first>b[i-1].first)
            cnt++;
        c[b[i].second]=cnt;
    }
    for(int i=1;i<=n;i++)
        a[i]=c[i];
    for(int i=1;i<=n;i++)
    {
        f[i]=sum(a[i])+1;
        res=max(res,f[i]);
        update(a[i]+1,f[i]);
    }
    printf("%d",res);
}
