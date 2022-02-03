#include <bits/stdc++.h>

using namespace std;

#define md 3*int(1e5)+5

const int mod=int(1e9)+7;

typedef pair<int,int> ii;

ii ans[md],t[md],c[md];

int n,r,f[md],b[md];

struct node
{
    int x,y;
}a[md];
bool cmp(const node& a,const node& b)
{
    return (a.x<b.x || ((a.x==b.x) && (a.y>b.y)));
}
inline void update(int x,int val,int sl)
{
    while (x<=r+1)
    {
        if (t[x].first<val)
        {
            t[x].first=val;
            t[x].second=sl;
        }
        else if (t[x].first==val)
        {
            t[x].second+=sl;
            if (t[x].second>mod)
                t[x].second-=mod;
        }
        x+=(x&(-x));
    }
}
inline ii sum(int x)
{
    ii ans=ii(0,0);
    while (x>0)
    {
        if (t[x].first>ans.first)
            ans=t[x];
        else if (t[x].first==ans.first)
        {
            ans.second+=t[x].second;
            if (ans.second>mod)
                ans.second-=mod;
        }
        x-=(x&(-x));
    }
    return ans;
}
main()
{
    //freopen("test.inp","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&a[i].x,&a[i].y);
    sort(a+1,a+1+n,cmp);
    //for(int i=1;i<=n;i++)
      //  cout << a[i].x<< " " <<a[i].y <<endl;
    for(int i=1;i<=n;i++)
    {
        c[i].first=a[i].y;
        c[i].second=i;
    }
    sort(c+1,c+1+n);
    b[c[1].second]=1;
    int cnt=1;
    for(int i=2;i<=n;i++)
    {
        if (c[i].first>c[i-1].first)
            cnt++;
        b[c[i].second]=cnt;
    }
    r=*max_element(b+1,b+1+n);
    b[n+1]=r+1;
    for(int i=1;i<=n+1;i++)
    {
        ii res=sum(b[i]);
        f[i]=res.first+1;
        res.second+=(res.second==0);
        if (i==n+1)
        {
            printf("%d\n%d",f[i]-1,res.second);
         //   break;
        }
        update(b[i]+1,f[i],res.second);
    }
}
