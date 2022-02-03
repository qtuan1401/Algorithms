#include <bits/stdc++.h>
using namespace std;
#define md 2*int(1e5)+5
int b[md];
int a[md],t[md],n,k,d[md],l[md],r[md],x[md],m,vl,vr,pl,pr;
char c;
inline void update(int x,int val)
{
    while (x<=md)
    {
        t[x]+=val;
        x+=(x&(-x));
    }
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
inline int bs(int l,int r,int val)
{
    int pos=0;
    while (l<=r)
    {
        int mid=(l+r)>>1;
        if (sum(mid)-vl>=val)
        {
            pos=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    return pos;
}
main()
{
    //freopen("test.inp","r",stdin);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> c;
        scanf("%d",&x[i]);
        if (c!='?')
            b[++m]=x[i];
        if (c=='-')
            d[i]=-1;
        else if (c=='+')
            d[i]=1;
        else
            scanf("%d%d",&l[i],&r[i]);
    }
    sort(b+1,b+1+m);
    m=unique(b+1,b+1+m)-b-1;
    for(int i=1;i<=n;i++)
        if (!d[i])
        {
            pl=lower_bound(b+1,b+1+m,l[i])-b;
            pr=upper_bound(b+1,b+1+m,r[i])-b-1;
            //cout << pl << " "<<pr <<endl;
            vl=sum(pl-1);
            vr=sum(pr);
            if (vr-vl<k)
                printf("0\n");
            else
                printf("%d\n",b[bs(pl,pr,x[i])]);
        }
        else
        {
            int pos=lower_bound(b+1,b+1+m,x[i])-b;
            update(pos,d[i]);
        }
}
