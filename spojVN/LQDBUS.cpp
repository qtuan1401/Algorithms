#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=int(a);i<=int(b);i++)
#define md 2*int(1e5)+10
using namespace std;
struct node
{
    int x,vt;
}a[md];
bool cmp(const node& a,const node& b)
{
    return (a.x<b.x);
}
bool cmp1(const node& a,const node& b)
{
    return (a.vt<b.vt || (a.vt==b.vt && a.x<b.x));
}
int t[md];
int t1,k,n,m,w[md],r;
inline void update(int x,int val)
{
    while (x<=md && t[x]<val)
    {
        t[x]=max(t[x],val);
        x+=(x&(-x));
    }
}
inline int sum(int x)
{
    int res=0;
    while (x>0 && res!=m)
    {
        res=max(t[x],res);
        x-=(x&(-x));
    }
    return res;
}
main()
{
   // freopen("test.inp","r",stdin);
    scanf("%d%d",&n,&m);
    long long s=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&t1,&k);
        for(int j=1;j<=k;j++)
        {
            int x;
            scanf("%d",&x);
            if (x-s>=0)
            {
                r++;
                a[r].x=x-s;
                a[r].vt=i;
            }
        }
        s+=t1;
    }
    sort(a+1,a+1+r,cmp);
    int cnt=1;
    w[1]=a[1].x;
    a[1].x=1;
    for(int i=2;i<=r;i++)
        if (a[i].x!=w[cnt])
        {
            cnt++;
            w[cnt]=a[i].x;
            a[i].x=cnt;
        }
        else a[i].x=cnt;
    sort(a+1,a+1+r,cmp1);
    int res=0,time=s;
    for(int i=1;i<=r;i++)
    {
      //  cout << i<< endl;
        int x=min(m,sum(a[i].x)+1);
        update(a[i].x,x);
        if (x>res || (x==res && w[a[i].x]+s<time))
        {
            res=x;
            time=w[a[i].x]+s;
        }
    }
    printf("%d",time);
}
