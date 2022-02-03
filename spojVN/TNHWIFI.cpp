#include <bits/stdc++.h>
using namespace std;
#define md 30005
long long r,Max,a[1005][md],b;
int cnt,k,n,m,x,y;
inline int maxx(int a,int b)
{
    if (a<b) return b;
    return a;
}
inline int minn(int a,int b)
{
    if (a<b) return a;
    return b;
}
inline void add(int x,int y,long long r,long long b)
{
    long long bk=r*r;
    int d=maxx(x-r,1);
    int c=minn(x+r,m);
    for(int i=d;i<=c;i++)
    {
       int vt=y+int(sqrt(bk-(x-i)*(x-i)));
        a[i][minn(vt+1,n+1)]-=b;
        a[i][maxx(y-abs(vt-y),0)]+=b;
    }
}
main()
{
  //  freopen("test.inp","r",stdin);
    scanf("%d",&n);
    scanf("%d",&m);
    scanf("%d",&k);
    for(int i=1;i<=k;i++)
    {
        scanf("%d%d%lld%lld",&x,&y,&r,&b);
        add(x,y,r,b);
    }
    cnt=0;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
        {
            a[i][j]+=a[i][j-1];
            if (Max<a[i][j])
            {
                Max=a[i][j];
                cnt=1;
            }
            else if (Max==a[i][j]) cnt++;
        }
    printf("%lld\n%d",Max,cnt);
}
