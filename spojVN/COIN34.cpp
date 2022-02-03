#include <bits/stdc++.h>
#define forr(i,a,b) for(long long i=(a);i<=(b);i++)
#define forl(i,a,b) for(long long i=(b);i>=(a);i--)
using namespace std;
#define fi ""
#define fo ""
#define st first
#define nd second
#define Memset(a,x) memset(a,x,sizeof(a))
typedef long long int lli;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef unsigned long long int ulli;
const long Max=367980;
ll s1,a[35],x[35],f[1000001],n,t,res,j,i;
void init()
{
    a[1]=2;
    a[2]=3;
    a[3]=5;
    forr(i,4,34) a[i]=a[i-1]+a[i-2]+a[i-3];
}
void Try1(ll k,ll i,ll s,ll d)
{
    forr(j,x[i-1]+1,20-k+i)
    {
        x[i]=j;
        if (i==k) f[s+a[j]]=max(f[s+a[j]],d+1);
        else Try1(k,i+1,s+a[j],d+1);
    }
}
void Try2(ll k,ll i,ll s,ll d,ll s1)
{
    forr(j,x[i-1]+1,34-k+i)
    {
        x[i]=j;
        if (i==k)
        {
            //cout << s1 << " " << s << " " << a[j];
            //getchar();
            if (s1-s-a[j]>=0 && s1-s-a[j]<=Max)
            {
                if ((((s1-s-a[j]>0) && (f[s1-s-a[j]]>0))) || (s1-s-a[j]==0)) res=max(res,f[s1-s-a[j]]+d+1);
            }
        }
        else Try2(k,i+1,s+a[j],d+1,s1);
    }
}
main()
{
    init();
    x[0]=0;
    forr(i,1,20) Try1(i,1,0,0);
    x[0]=20;
    cin >> t;
    forr(j,1,t)
    {
        cin >> s1;
        res=0;
        if (s1<=367980) res=f[s1];
        else
        {
            forr(i,1,14) Try2(i,1,0,0,s1);
        }
        cout << "Case #" << j << ": ";
        if (res==0) cout << -1 << endl;
        else cout << res << endl;
    }
}
