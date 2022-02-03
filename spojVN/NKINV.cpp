#include <bits/stdc++.h>
using namespace std;
#define md 2*int(1e5)+5
int a[md],temp[md],n,t;
long long res;

long long Merge(int l,int mid,int r)
{
    int i,j,k;
    i=k=l;
    j=mid;
    long long res=0;
    while ((i<=mid-1) && (j<=r))
    {
        if (a[i]<=a[j])
            temp[k++]=a[i++];
        else
        {
            temp[k++]=a[j++];
            res+=(mid-i);
        }
    }
    while (i<=mid-1)
        temp[k++]=a[i++];
    while (j<=r)
        temp[k++]=a[j++];
    for(int i=l;i<=r;i++)
        a[i]=temp[i];
    return res;
}
long long merge_sort(int l,int r)
{
    long long res=0;
    if (l<r)
    {
        int mid=(l+r)>>1;
        res=merge_sort(l,mid);
        res+=merge_sort(mid+1,r);
        res+=Merge(l,mid+1,r);
    }
    return res;
}
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    printf("%lld",merge_sort(1,n));
}
