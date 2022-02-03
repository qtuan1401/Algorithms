#include <bits/stdc++.h>
using namespace std;
long a[500000],t[500000];
long i,m,n,q,k,u,v;
void it1(long i,long l,long r)
{
    long mid;
    if (l==r)
    {
        t[i]=a[l];
        return;
    }
    mid=(l+r)/2;
    it1(i*2,l,mid);
    it1(i*2+1,mid+1,r);
    t[i]=max(t[i*2],t[i*2+1]);
}
long it2(long i,long l,long r,long u,long v)
{
    long mid,maxr,maxl;
    if (v<l || r<u) return 0;
    else if (u<=l && r<=v) return t[i];
    else
    {
        mid=(l+r)/2;
        maxl=it2(i*2,l,mid,u,v);
        maxr=it2(i*2+1,mid+1,r,u,v);
        return max(maxl,maxr);
    }
}
int main()
{
    cin >> n >> m;
    for (i=0;i<=n;i++) a[i]=0;
    for (i=1;i<=m;i++)
    {
        cin >> u >> v >> k;
        a[u]=a[u]+k;
        a[v+1]=a[v+1]-k;
    }
    for (i=1;i<=n;i++) a[i]=a[i]+a[i-1];
    it1(1,1,n);
    cin >> q;
    for (i=1;i<=q;i++)
    {
        cin >> u >> v;
        cout << it2(1,1,n,u,v)<<endl;
    }
    return 0;
}