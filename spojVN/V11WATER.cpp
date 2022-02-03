#include <bits/stdc++.h>
using namespace std;
#define md 100001
int n;
int l[md],r[md],a[md];
long long res;
main()
{
    //freopen("test.inp","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        l[i]=max(a[i],l[i-1]);
    for(int i=n;i>=1;i--)
        r[i]=max(a[i],r[i+1]);
    for(int i=1;i<=n;i++)
        if (a[i]<min(l[i],r[i]))
            res+=min(l[i],r[i])-a[i];
    printf("%lld",res);
}
