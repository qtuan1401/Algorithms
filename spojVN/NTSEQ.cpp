#include <bits/stdc++.h>
using namespace std;
#define md int(1e5)+5
const int mod=int(1e9)+7;
typedef pair<int,int> ii;
ii ans[md],t[md],b[md];
int n,r,a[md],f[md],c[md];
inline ii sum(int x)
{
    ii ans=ii(0,0);
    while (x>0)
    {
        if (ans.first<t[x].first)
            ans=t[x];
        else if (ans.first==t[x].first)
        {
            ans.second+=t[x].second;
            if (ans.second>mod)
                ans.second-=mod;
        }
        x-=(x&(-x));
    }
    return ans;
}

inline void update(int x,int val,int sl)
{
    while (x<=r+1)
    {
        if (t[x].first<val)
            t[x].first=val,t[x].second=sl;
        else if (t[x].first==val)
        {
            t[x].second+=sl;
            if (t[x].second>mod)
                t[x].second-=mod;
        }
        x+=(x&(-x));
    }
}
main()
{
    //freopen("test.inp","r",stdin);
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
        r=max(r,a[i]);
    a[n+1]=r+1;
    for(int i=1;i<=n+1;i++)
    {
        ii res=sum(a[i]);
        f[i]=res.first+1;
        if (res.second==0)
            res.second++;
        if (i==n+1)
            printf("%d",res.second);
        update(a[i]+1,f[i],res.second);
    }
//    printf("%d",res.second);
}
